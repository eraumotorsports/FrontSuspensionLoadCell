/*
  Front suspension shock rod load cell
  Reads an analog input on pin 0, converts to pounds and prints the results to the serial monitor.
   
 */
 
 // Pin Configuration
 #define PIN_INPUT  A0
 #define PIN_VREF   DAC1
 
 // Constants
 #define VREF_OFFSET_CAL 1930
 
 int sensorValue, load;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  analogWriteResolution(12); // change output resultion to 12 bit
  analogWrite(PIN_VREF, VREF_OFFSET_CAL); // set the neutral position to 2048, make sure it reads 2048 with no load!
  analogReadResolution(12); // set read resolution to 12 bit
}

void loop() {
  // read the input on analog pin 0:
  sensorValue = analogRead(PIN_INPUT); // read op amp signal
  
  load = map(sensorValue, 0, 4095, -1000, 1000); // map 0-4095 to -1000 pounds to 1000 pounds
  
  Serial.println(load);
  delay(1);        // delay in between reads for stability
}
