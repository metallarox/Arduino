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

#define delayCycle 30000
#define delayStep 1000

// Gate Motors Pin
#define openLeftPin 2
#define closeLeftPin 3
#define openRightPin 4
#define closeRightPin 5

// Latch
#define latchPin 6

// Walking gate lamp
#define lampPin 7

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

}

void open() {
	digitalWrite(lampPin, HIGH);					//ON walking gate lamp
	digitalWrite(latchPin, HIGH);					//On latch
	digitalWrite(openLeftPin, HIGH);				//ON L open
	delay(delayStep);								//delay 1 sec
	digitalWrite(openRightPin, HIGH);				//ON R open
	delay(delayCycle);
	digitalWrite(latchPin, LOW);					//OFF latch
	digitalWrite(openLeftPin, LOW);					//OFF L open
	digitalWrite(openRightPin, LOW);				//OFF R open
	digitalWrite(lampPin, LOW);						//OFF walking gate lamp

}

void close() {
	digitalWrite(lampPin, HIGH);					//ON walking gate lamp
	digitalWrite(latchPin, HIGH);					//On latch
	digitalWrite(closeLeftPin, HIGH);				//ON L close
	delay(delayStep);								//delay 1 sec
	digitalWrite(closeRightPin, HIGH);				//ON R close
	delay(delayCycle);
	digitalWrite(latchPin, LOW);					//OFF latch
	digitalWrite(closeLeftPin, LOW);				//OFF L close
	digitalWrite(closeRightPin, LOW);				//OFF R close
	digitalWrite(lampPin, LOW);						//OFF walking gate lamp
}
