
#include <LiquidCrystal.h>
#include <dht_nonblocking.h>

#define DHT_SENSOR_TYPE DHT_TYPE_11

constexpr byte DHT_SENSOR_PIN = 2;
constexpr unsigned long MEASUREMENT_INTERVAL_MS = 3000;

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// 温湿度センサー
DHT_nonblocking dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

// 温湿度を測定する
bool measureEnvironment(float &temperature, float &humidity) {
  static unsigned long lastMeasurement = millis();

  if (millis() - lastMeasurement < MEASUREMENT_INTERVAL_MS) {
    return false;
  }

  if (!dht_sensor.measure(&temperature, &humidity)) {
    return false;
  }

  lastMeasurement = millis();
  return true;
}

// 測定結果をLCDに表示する
void displayEnvironment(float temperature, float humidity) {
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Humi: ");
  lcd.print(humidity, 1);
  lcd.print(" %");
}

// 測定結果をシリアルモニターに出力する
void logEnvironment(float temperature, float humidity) {
  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.print(" C, Humidity: ");
  Serial.print(humidity, 1);
  Serial.println("%");
}

void setup() {
  Serial.begin(115200);

  lcd.begin(16, 2);
  lcd.print("Measuring...");
}

void loop() {
  float temperature;
  float humidity;

  if (measureEnvironment(temperature, humidity)) {
    displayEnvironment(temperature, humidity);
    logEnvironment(temperature, humidity);
  }
}
