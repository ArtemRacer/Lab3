#include <Wire.h>
#include <SFE_BMP180.h>
#include "DFRobot_RGBLCD1602.h"
#include <LiquidCrystal_I2C.h>

SFE_BMP180 bmp180;
DFRobot_RGBLCD1602 lcd(/*RGBAddr*/0x60 ,/*lcdCols*/16,/*lcdRows*/2);  //16 characters and 2 lines of show
LiquidCrystal_I2C lcd2(0x3F,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  lcd.init();
  lcd2.init();
  lcd2.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" Arduino! ");
  lcd2.setCursor(0, 0);
  lcd2.print(" Arduino2! ");
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

  if (stats_l != 0) {
    delay(1000);
    stats_l = bmp180.getTemperature(Temp);

    if (stats_l != 0) {
      stats_l = bmp180.startPressure(3);

      if (stats_l != 0) {
        delay(stats_l);
        stats_l = bmp180.getPressure(Pressure, Temp);

        if (stats_l != 0) {
          Serial.print("Pressure: ");
          Serial.print(Pressure);
          Serial.println(" h_Pascal");

          Serial.print("Temp: ");
          Serial.print(Temp);
          Serial.println(" degree-C");
          
          lcd.setCursor(0, 0);
          lcd.print("Pressure: ");
          lcd.print(Pressure);
          lcd.setCursor(0, 1);
          lcd.print("Temp: ");
          lcd.print(Temp);
           lcd2.setCursor(0, 0);
          lcd2.print("Pressure: ");
          lcd2.print(Pressure);
          lcd2.setCursor(0, 1);
          lcd2.print("Temp: ");
          lcd2.print(Temp);
        }
      }
    }
  }
}
