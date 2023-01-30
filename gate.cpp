#include "gate.h"
#include "globals.h"

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
	digitalWrite(openLeftPin, RELAY_OFF);
	digitalWrite(openRightPin, RELAY_OFF);
	digitalWrite(closeLeftPin, RELAY_OFF);
	digitalWrite(closeRightPin, RELAY_OFF);

	Serial.println("The gate has been stopped");
}

void Gate::setState(bool state){
	this->state = state;
}

void Gate::open() {
	Serial.println("The gate is now opening");				// Opening message
	digitalWrite(lampPin, RELAY_ON);						// ON Walking gate lamp
	digitalWrite(latchPin, RELAY_ON);						// On Latch
	digitalWrite(openLeftPin, RELAY_ON);					// ON Left open
	Serial.println("Delay step");
	delay(delayStep);										// Delay step time
	digitalWrite(openRightPin, RELAY_ON);					// ON Right open
	Serial.println("Delay cycle");
	delay(delayCycle);										// Delay cycle time
	digitalWrite(latchPin, RELAY_OFF);						// OFF Latch
	digitalWrite(openLeftPin, RELAY_OFF);					// OFF Left open
	digitalWrite(openRightPin, RELAY_OFF);					// OFF Right open
	digitalWrite(lampPin, RELAY_OFF);						// OFF Walking gate lamp
	Serial.println("Fine");
	this->setState(OPEN);
}

void Gate::close() {
	Serial.println("The gate is now closing");				// Closing message
	digitalWrite(lampPin, RELAY_ON);						// ON Walking gate lamp
	digitalWrite(latchPin, RELAY_ON);						// On Latch
	digitalWrite(closeLeftPin, RELAY_ON);					// ON Left close
	Serial.println("Delay step");
	delay(delayStep);										// Delay step from one side to open
	digitalWrite(closeRightPin, RELAY_ON);					// ON Right close
	Serial.println("Delay cycle");
	delay(delayCycle);										// Delay cycle time
	digitalWrite(latchPin, RELAY_OFF);						// OFF Latch
	digitalWrite(closeLeftPin, RELAY_OFF);					// OFF Left close
	digitalWrite(closeRightPin, RELAY_OFF);					// OFF Right close
	digitalWrite(lampPin, RELAY_OFF);						// OFF Walking gate lamp
	Serial.println("Fine");
	this->setState(CLOSED);
}