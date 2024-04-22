#include <Wire.h>
#include <SFE_BMP180.h>

SFE_BMP180 bmp180;

void setup() {
  Serial.begin(9600);
  bool okk = bmp180.begin();

  if (okk) {
    Serial.print("BMP180 initialiazed");
  }
}

void loop() {

  char stats_l;
  double Temp, Pressure;
  bool okk = false;

  stats_l = bmp180.startTemperature();

  if (stats_l !=0) {
    delay(1000);
    stats_l = bmp180.getTemperature(Temp);

    if (stats_l !=0) {
      stats_l = bmp180.startPressure(3);

      if (stats_l !=0) {
        delay(stats_l);
        stats_l = bmp180.getPressure(Pressure, Temp);

        if (stats_l !=0) {
          Serial.print("Pressure: ");
          Serial.print(Pressure);
          Serial.println(" h_Pascal");

          Serial.print("Temp: ");
          Serial.print(Temp);
          Serial.println(" degree-C");
        }
      }
    }
  }
}
