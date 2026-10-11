const int LED_PIN = 13;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  Serial.println("High");
  digitalWrite(LED_PIN, HIGH);
  delay(2000);
  Serial.println("Low");
  digitalWrite(LED_PIN, LOW);
  delay(2000);
}
