/*
	Author:		Parussini Elia
	Co-Author:	Romano Federico
	eMail:		elia.parussini@gmail.com
	eMail:		federicoromano1999@gmail.com

	Board:		Arduino Nano

	Title:
		Gate automation project
	Description:
		Centralina piccolina del portoncino, carino, piccolino,
		bello e pafuttelo, della calcelcestruzzaggine
*/

/*
	Pinout:

	D0 -> TX
	D1 -> RX
	D2 <- NC Light barrier
	D3 <- NO Pulse
	D4 -> K3 R open
	D5 -> K4 R close
	D6 -> K5 Latch
	D7 -> K6 Lamp
	D8 -> K7 NC
	D9 -> K8 NC
	D10
	D11 -> K1 L open
	D12 -> K2 L close
	D13
*/

#define delayCycle 30000									// Opening/closing gate total time
#define delayStep 1000										// Time to wait until start the other gate side

#define CLOSED 0											// The gate is close
#define OPEN 1												// The gate is open

#define RELAY_ON LOW										// Turn on the relay on the board
#define RELAY_OFF HIGH										// Turn off the relay on the board

// Pins defining
// Gate Motors Pin
#define openLeftPin 2										// K1, Open the left gate
#define closeLeftPin 3										// K2, Close the left gate
#define openRightPin 4										// K3, Open the right gate
#define closeRightPin 5										// K4, Close the right gate

#define latchPin 6											// K5, Latch to lock the whole gate

#define lampPin 7											// K6, Walking gate lamp

//Interrupts
#define barrierPin 11										// Light curtain, NC
#define buttonPin 12										// Button key opener, NO

class Gate{
	public:
		bool isMoving();
		bool isOpen();
		bool isClosed();
		void stop();
		void setState(bool s);
	private:
		bool move;
		bool state;
};

bool Gate::isMoving(){
	return Gate::move;
}

bool Gate::isOpen(){
	return state;
}

bool Gate::isClosed(){
	return !state;
}

void Gate::stop(){
	digitalWrite(openLeftPin, LOW);
	digitalWrite(openRightPin, LOW);
	digitalWrite(closeLeftPin, LOW);
	digitalWrite(closeRightPin, LOW);

	Serial.println("The gate has been stopped");
}

void Gate::setState(bool s){
	state = s;
}

// Globals
Gate gate;
char emcy;

// Timers
unsigned long requestTime;

void setup() {
	//Pin definition
	// Inputs
	pinMode(buttonPin, INPUT_PULLUP);						// NO Button key opener

	// Interrupts
	//attachInterrupt(barrierPin, emergency, FALLING);		// NC, barrier
	pinMode(barrierPin, INPUT_PULLUP);						// NC, barrier

	// Outputs
	// Gate motors
	pinMode(openLeftPin, OUTPUT);
	pinMode(closeLeftPin, OUTPUT);
	pinMode(openRightPin, OUTPUT);
	pinMode(closeRightPin, OUTPUT);

	// Latch
	pinMode(latchPin, OUTPUT);

	// Lamp
	pinMode(lampPin, OUTPUT);

	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);

	// Initializing the serial communication
	Serial.begin(9600);

	// The contraption is not in emcy
	emcy = false;

	gate.stop();
	gate.setState(CLOSED);
}

void loop() {
	if(!emcy) {
		// The machine is not in emergency state
		if(!digitalRead(buttonPin)){
			// There is a request from the button
			//requestTime = millis();
			if(gate.isOpen()){
				close();
			}
			else if(gate.isClosed()){
				open();
			}
			else if(gate.isMoving()){
				// The gate is moving
				gate.stop();
			}
		}

	}
	else {
		Serial.write("There is something in the barrier");
	}

}

void open() {
	Serial.println("The gate is now opening");				// Opening message
	digitalWrite(lampPin, RELAY_ON);							// ON Walking gate lamp
	digitalWrite(latchPin, RELAY_ON);							// On Latch
	digitalWrite(openLeftPin, RELAY_ON);						// ON Left open
	Serial.println("Delay step");
	delay(delayStep);										// Delay step time
	digitalWrite(openRightPin, RELAY_ON);						// ON Right open
	Serial.println("Delay cycle");
	delay(delayCycle);										// Delay cycle time
	digitalWrite(latchPin, RELAY_OFF);							// OFF Latch
	digitalWrite(openLeftPin, RELAY_OFF);							// OFF Left open
	digitalWrite(openRightPin, RELAY_OFF);						// OFF Right open
	digitalWrite(lampPin, RELAY_OFF);								// OFF Walking gate lamp
	Serial.println("Fine");
	gate.setState(OPEN);
}

void close() {
	Serial.println("The gate is now closing");				// Closing message
	digitalWrite(lampPin, RELAY_ON);							// ON Walking gate lamp
	digitalWrite(latchPin, RELAY_ON);							// On Latch
	digitalWrite(closeLeftPin, RELAY_ON);						// ON Left close
	Serial.println("Delay step");
	delay(delayStep);										// Delay step from one side to open
	digitalWrite(closeRightPin, RELAY_ON);						// ON Right close
	Serial.println("Delay cycle");
	delay(delayCycle);										// Delay cycle time
	digitalWrite(latchPin, RELAY_OFF);							// OFF Latch
	digitalWrite(closeLeftPin, RELAY_OFF);						// OFF Left close
	digitalWrite(closeRightPin, RELAY_OFF);						// OFF Right close
	digitalWrite(lampPin, RELAY_OFF);								// OFF Walking gate lamp
	Serial.println("Fine");
	gate.setState(CLOSED);
}

void emergency() {
	emcy = true;
	gate.stop();
}
