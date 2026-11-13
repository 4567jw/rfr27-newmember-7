#include <Arduino.h>


const uint8_t MUX_S0 = 2;
const uint8_t MUX_S1 = 3;
const uint8_t MUX_S2 = 4;
const uint8_t MUX_S3 = 5;
const uint8_t MUX_SIG_PIN = A0;
const uint8_t RED_LED_PIN = 6;


const uint8_t NUM_CHANNELS = 16;
const float TEMP_THRESHOLD = 60.0; //temp i ncelcius
const unsigned long TEMP_CHECK_INTERVAL = 1000; //1 second


void setup() {
  Serial.begin(115200);

  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(MUX_SIG_PIN, INPUT);

  digitalWrite(RED_LED_PIN, LOW); 

  pinMode(MUX_S0, OUTPUT);
  pinMode(MUX_S1, OUTPUT);
  pinMode(MUX_S2, OUTPUT);
  pinMode(MUX_S3, OUTPUT);

}

void loop() {

}