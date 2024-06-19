#include "dht11.h"
#include "LiquidCrystal_I2C.h"
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);

dht11 DHT11;

#define DHT11PIN 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  lcd.init();
  lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:
  int chk = DHT11.read(DHT11PIN);

  float temp = DHT11.temperature;
  lcd.setCursor(0,0);
  lcd.print("Current Temp :");
  lcd.setCursor(0,1);
  lcd.print(temp);
  Serial.println(temp);
  //Serial.println((float)DHT11.temperature,2);

  if(temp >= 18) {
    digitalWrite(3,HIGH);
  }else{
    digitalWrite(3,LOW);
  }
  
  delay(2000);
}
