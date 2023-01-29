/*
centralina piccolina del portoncino, carino, piccolino,
bello e pafuttelo, della calcelcestrruzza

D0 -> TX
D1 -> RX
D2 -> K1 APRE SX
D3 -> K2 CHIUDE SX
D4 -> K3 APRE DX
D5 -> K4 CHIUDE DX
D6 -> K5 CHIAVISTELLO
D7 -> K6 FARETTO VIALE
D8 -> K7 NC
D9 -> K8 NC
D10
D11 <- FOTOCELLULA
D12 <- COMANDO
D13
*/

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  
  pinMode(11, INPUT);
  pinMode(12, INPUT);
}

void loop() {
  digitalWrite(10, HIGH);  
  delay(1000);                   
  digitalWrite(10, LOW);  
  delay(1000);                     
}
