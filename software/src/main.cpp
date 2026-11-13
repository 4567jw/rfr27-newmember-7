#include <Arduino.h>


const uint8_t S0 = 2;
const uint8_t S1 = 3;
const uint8_t S2 = 4;
const uint8_t S3 = 5;
const uint8_t COM = A0;
const uint8_t RED_LED_PIN = 6;


const uint8_t NUM_CHANNELS = 16;
const float TEMP_THRESHOLD = 60.0; //temp i ncelcius
const unsigned long TEMP_CHECK_INTERVAL = 1000; //1 second

void selectChannel(uint8_t ch) {
  digitalWrite(S0, bitRead(ch,0));
  digitalWrite(S1, bitRead(ch,1));
  digitalWrite(S2, bitRead(ch,2));
  digitalWrite(S3, bitRead(ch,3));

  delay(10);
}


void setup() {
  Serial.begin(115200);

  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(COM, INPUT);

  digitalWrite(RED_LED_PIN, LOW); 

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

}

float readTempC(uint16_t raw) {
  float voltage = raw * 5.0 / 1023;
  float tempC = 25.0 + (voltage - 0.650) / (-0.002);

  return tempC;
}


void loop() {
  for (uint8_t ch = 0; ch < NUM_CHANNELS; ch++) {
    selectChannel(ch);
    analogRead(COM);
    uint16_t rawADC = analogRead(COM);

    float temp = readTempC(rawADC);

    if (temp > TEMP_THRESHOLD) {
      digitalWrite(RED_LED_PIN, HIGH);
      delay(TEMP_CHECK_INTERVAL);
    } else {
      digitalWrite(RED_LED_PIN, LOW);
    }
  }


}