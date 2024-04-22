// I2C Slave

#include <Wire.h>
int LED = 13;
int x = 0;

void setup() {
  // Define the LED pin as Output
  pinMode (LED, OUTPUT);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}

void loop() {
  //If value received is 0 blink LED for 300 ms
  Serial.println(x);
  if (x <=150) digitalWrite(LED, HIGH);
  else digitalWrite(LED, LOW);
}
