/*
  Front suspension shock rod load cell
  Reads an analog input on pin 0, converts to pounds and prints the results to the serial monitor.
   
 */

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  analogWriteResolution(12); // change output resultion to 12 bit
  analogWrite(DAC1, 1930); // set the neutral position to 2048, make sure it reads 2048 with no load!
}

void loop() {
  // read the input on analog pin 0:
  analogReadResolution(12); // set read resolution to 12 bit
  int sensorValue = analogRead(A0); // read op amp signal
  
  int load = map(sensorValue, 0, 4095, -1000, 1000); // map 0-4095 to -1000 pounds to 1000 pounds
  
  Serial.println(load);
  delay(1);        // delay in between reads for stability
}
