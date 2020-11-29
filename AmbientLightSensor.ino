#include "AmbientLightSensor.h"

const int analogInPin = A3;

int sensorValue = 0;
int outputValue = 0;
int lastValue = -1;

void setup() {
  Serial.begin(115200);
  AmbientLightSensor.begin();
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 10000);

  if (outputValue != lastValue) {
    // print the results to the Serial Monitor:
    Serial.print("sensor = ");
    Serial.print(sensorValue);
    Serial.print("\t output = ");
    Serial.println(outputValue);
  
    AmbientLightSensor.report(outputValue);
    lastValue = outputValue;
  }

  

  // wait 100 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(1000);
}
