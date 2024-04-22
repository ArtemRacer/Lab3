// I2C Master
#include <Wire.h>
int LED=13;

int x = 0;

void setup() {
  // Start the I2C Bus as Master
  Wire.begin(); 
  Serial.begin(9600);
  pinMode(LED,OUTPUT);

}

void loop() {
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
 
  x++; // Increment x
  if (x > 300) x = 0; // `reset x once it gets 6
  Serial.println(x);
  if (x <=150) digitalWrite(LED, HIGH);
  else digitalWrite(LED, LOW);
   
}
