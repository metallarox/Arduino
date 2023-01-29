/*
	centralina piccolina del portoncino, carino, piccolino,
	bello e pafuttelo, della calcelcestrruzza

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

//Clear errors on vscode
void digitalWrite(int t1, bool t2);
void delay(int t1);

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
	// Outputs
	pinMode(openLeftPin, OUTPUT);
	pinMode(closeLeftPin, OUTPUT);
	pinMode(openRightPin, OUTPUT);
	pinMode(closeRightPin, OUTPUT);
	pinMode(latchPin, OUTPUT);
	pinMode(lampPin, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);

	// Inputs
	pinMode(11, INPUT);
	pinMode(12, INPUT);
}

void loop() {
	/*
	d12 on pulse
	
	OPEN
	6 on latch
	2 on L open
	delay 1S
	4 on R open
	delay 30S
	6 off 
	2 off
	4 off

	delay 60S
	
	CLOSE
	6 on latch
	3 on L close
	delay 1S
	5 on R close
	delay 30S
	6 off latch
	3 off L close
	5 off R close
*/
}

void open(){

}

void close(){
/*
	CLOSE
	6 on latch
	3 on L close
	delay 1S
	5 on R close
	delay 30S
	6 off latch
	3 off L close
	5 off R close
*/

	digitalWrite(latchPin, HIGH);					// Unlock the latch

	digitalWrite(closeLeftPin, HIGH);				// Close left gate
	delay(delayStep);
	digitalWrite(closeRightPin, HIGH);
	delay(delayCycle);
	digitalWrite(closeLeftPin, LOW);				// Close left gate
	digitalWrite(closeRightPin, LOW);
}
