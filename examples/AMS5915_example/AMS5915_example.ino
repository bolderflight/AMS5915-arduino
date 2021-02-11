/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2021 Bolder Flight Systems
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
* and associated documentation files (the "Software"), to deal in the Software without restriction, 
* including without limitation the rights to use, copy, modify, merge, publish, distribute, 
* sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is 
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all copies or 
* substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
* BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
* DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "ams5915.h"

/* 
* An AMS5915 object, which is a
* static pressure sensure at I2C
* address of 0x12, on I2C bus 0,
* and is a AMS5915-1200-B
*/
Ams5915 static_pres(&Wire, 0x12, Ams5915::AMS5915_1200_B);

void setup() {
  /* Serial to display data */
  Serial.begin(9600);
  while(!Serial){}
  /* Starting communication with the static pressure transducer */
  if (!static_pres.Begin()) {
    Serial.println("Error communicating with sensor");
    while(1){}
  }
}

void loop() {
  /* Read the sensor */
  if (static_pres.Read()) {
    /* Display the data */
    Serial.print(static_pres.pressure_pa(), 6);
    Serial.print("\t");
    Serial.println(static_pres.die_temperature_c(), 6);
  }
  delay(10);
}
