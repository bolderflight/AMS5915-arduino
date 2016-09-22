/*
AMS5915_example.ino
Brian R Taylor
brian.taylor@bolderflight.com
2016-09-22

Copyright (c) 2016 Bolder Flight Systems

Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
and associated documentation files (the "Software"), to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, 
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or 
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "AMS5915.h"

// an AMS5915 object, which is a
// static pressure sensure at I2C
// address of 0x10, on I2C bus 0,
// and is a AMS5915-1200-B
AMS5915 sPress(0x10,0,"AMS5915-1200-B");

void setup() {
  // serial to display data
  Serial.begin(9600);

  // starting communication with the 
  // static pressure transducer
  sPress.begin();
}

void loop() {
  float pressure, temperature;

  // getting both the temperature (C) and pressure (PA)
  sPress.getData(&pressure,&temperature);

  // displaying the data
  Serial.print(pressure,6);
  Serial.print("\t");
  Serial.println(temperature,6);
  delay(100);

  // getting just the pressure, PA
  pressure = sPress.getPressure();
  delay(10);

  // getting just the temperature, C
  temperature = sPress.getTemperature();
  delay(10);

  // displaying the data
  Serial.print(pressure,6);
  Serial.print("\t");
  Serial.println(temperature,6);
  delay(100);
}

