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

#include "globals.h"

#include "gate.h"

void setupRealyBoard(){
	// Motors
	digitalWrite(openLeftPin, RELAY_OFF);
	digitalWrite(openRightPin, RELAY_OFF);
	digitalWrite(closeLeftPin, RELAY_OFF);
	digitalWrite(closeRightPin, RELAY_OFF);

	// Latch
	digitalWrite(latchPin, RELAY_OFF);

	// Lamp
	digitalWrite(lampPin, RELAY_OFF);

	// Not connected pins
	digitalWrite(8, RELAY_OFF);
	digitalWrite(9, RELAY_OFF);
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

	setupRealyBoard();

	// The contraption is not in emcy
	emcy = false;

	gate.stop();
	gate.setState(CLOSED);

	// Initializing the serial communication
	Serial.begin(9600);
}

void loop() {
	if(!emcy) {
		// The machine is not in emergency state
		if(!digitalRead(buttonPin)){
			// There is a request from the button
			//requestTime = millis();
			if(gate.isOpen()){
				gate.close();
			}
			else if(gate.isClosed()){
				gate.open();
			}
			else if(gate.isMoving()){
				// The gate is moving
			}
		}

	}
	else {
		Serial.write("There is something in the barrier");
	}

}

void emergency() {
	emcy = true;
	gate.stop();
}
