/*
	Author:		Parussini Elia
	Co-Author:	Romano Federico
	eMail:		mail@mail.com
	eMail:		federicoromano1999@gmail.com

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
	D2 -> K1 L open
	D3 -> K2 L close
	D4 -> K3 R open
	D5 -> K4 R close
	D6 -> K5 Latch
	D7 -> K6 Lamp
	D8 -> K7 NC
	D9 -> K8 NC
	D10
	D11 <- NC Light curtain 
	D12 <- NO Pulse 
	D13
*/

#define delayCycle 30000							// Opening/closing gate total time
#define delayStep 1000								// Time to wait until start the other gate side
#define OPEN 0
#define CLOSE 1
#define MOVING 2

// Pins defining
// Gate Motors Pin
#define openLeftPin 2								// K1, Open the left gate
#define closeLeftPin 3								// K2, Close the left gate
#define openRightPin 4								// K3, Open the right gate
#define closeRightPin 5								// K4, Close the right gate

#define latchPin 6									// K5, Latch to lock the whole gate

#define lampPin 7									// K6, Walking gate lamp

// Globals
char gateState;

void setup() {
	// Inputs
	pinMode(11, INPUT);
	pinMode(12, INPUT);

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
}

void loop() {
	bool gateState = CLOSED;

}

void open() {
	digitalWrite(lampPin, HIGH);					// ON Walking gate lamp
	digitalWrite(latchPin, HIGH);					// On Latch
	digitalWrite(openLeftPin, HIGH);				// ON Left open
	delay(delayStep);								// Delay step time
	digitalWrite(openRightPin, HIGH);				// ON Right open
	delay(delayCycle);								// Delay cycle time
	digitalWrite(latchPin, LOW);					// OFF Latch
	digitalWrite(openLeftPin, LOW);					// OFF Left open
	digitalWrite(openRightPin, LOW);				// OFF Right open
	digitalWrite(lampPin, LOW);						// OFF Walking gate lamp
}

void close() {
	digitalWrite(lampPin, HIGH);					// ON Walking gate lamp
	digitalWrite(latchPin, HIGH);					// On Latch
	digitalWrite(closeLeftPin, HIGH);				// ON Left close
	delay(delayStep);								// Delay step from one side to open
	digitalWrite(closeRightPin, HIGH);				// ON Right close
	delay(delayCycle);								// Delay cycle time
	digitalWrite(latchPin, LOW);					// OFF Latch
	digitalWrite(closeLeftPin, LOW);				// OFF Left close
	digitalWrite(closeRightPin, LOW);				// OFF Right close
	digitalWrite(lampPin, LOW);						// OFF Walking gate lamp
}
