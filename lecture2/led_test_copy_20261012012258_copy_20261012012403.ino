
void light_duration(int output, int msec) {
  digitalWrite(output, HIGH);
  delay(msec);
  digitalWrite(output, LOW);
}

void setup() {
  Serial.begin(115200);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

// void loop() {
//   // do nothing
// }

void loop() {
  light_duration(12, 500);
  light_duration(11, 500);
  light_duration(10, 500);
  light_duration(9, 500);
}
