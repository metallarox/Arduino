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
