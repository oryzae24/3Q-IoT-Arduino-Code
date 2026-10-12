
constexpr byte LED_PINS[] = {12, 11, 10, 9, 8};
constexpr unsigned long LIGHT_DURATION_MS = 500;

// LEDの出力状態を設定し、シリアルにも記録する
void setLedState(byte pin, byte state) {
  digitalWrite(pin, state);

  Serial.print("D");
  Serial.print(pin);
  Serial.print(": ");
  Serial.println(state == HIGH ? "HIGH" : "LOW");
}

// LEDを指定時間だけ点灯させる
void lightLedFor(byte pin, unsigned long durationMs) {
  setLedState(pin, HIGH);
  delay(durationMs);
  setLedState(pin, LOW);
}

void setup() {
  Serial.begin(115200);

  for (byte pin : LED_PINS) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  for (byte pin : LED_PINS) {
    lightLedFor(pin, LIGHT_DURATION_MS);
  }
}
