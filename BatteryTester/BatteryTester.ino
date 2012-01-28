#include <SoftwareSerial.h>

// http://www.sparkfun.com/datasheets/Components/LED/7-Segment/SFE-0012-DS-7segmentSerial-v41.pdf
SoftwareSerial lcd(2, 4);

int analogPin = 2;
int val = 0;

#define DELAY 600

void setup()
{
  Serial.begin(9600);
  
  pinMode(4, OUTPUT);
  lcd.begin(9600);
  delay(DELAY);
  lcd.print("v");

  lcd.print(0x77);
  delay(DELAY);
  lcd.print(0x00);
  delay(DELAY);
}

void loop()
{ 
  // analogRead=() outputs a value between 0 and 1024
  // to get the actual voltage we need to multiply with the reference voltage
  // and divide the resolution
  float val = (float) analogRead(analogPin)*5.0/1024.0;
  int output = (int) (val*100);
  
  if (output < 10) {
    lcd.print("000");
  } else {
    lcd.print(output);
  }
  
  delay(DELAY);
  
  lcd.print("v");
 
}

