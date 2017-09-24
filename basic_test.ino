/* Tiny RTC DS1307 I2C Module (DS1307) [S029] : http://rdiot.tistory.com/105 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
RTC_Millis rtc;
String dt;
String ut;
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
  
  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
 
  delay(1000);
  lcd.clear();
}
 
void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S029:DS1307");
 
  DateTime now = rtc.now();
 
  dt = (String)now.year()+"/";
  dt += (String)now.month()+"/";
  dt += (String)now.day()+" ";
  dt += (String)now.hour()+":";
  dt += (String)now.minute()+":";
  dt += (String)now.second();
 
  lcd.setCursor(0,1);
  lcd.print(dt);
 
  ut = (String)now.unixtime();

  lcd.setCursor(0,2);
  lcd.print("unixtime="+ut);
}
