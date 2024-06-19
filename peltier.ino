#include "dht11.h"
#include "LiquidCrystal_I2C.h"
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);

dht11 DHT11;

#define DHT11PIN 2    // 2번핀을 DHT11PIN 이라고 지정

void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT);  // 3번핀 릴레이 모듈 (펠티어 모듈)을 출력핀으로 설정
  lcd.init();         // LCD 초기화
  lcd.backlight();    // backlight 켜기

}

void loop() {
  int chk = DHT11.read(DHT11PIN);               // DHT11 센서 값을 받아와 chk 변수에 저장

  float temp = DHT11.temperature;               // DHT11 센서의 온도 값을 temp 변수에 저장
  lcd.setCursor(0,0);                           // LCD 커서를 0,0으로 초기화
  lcd.print("Current Temp :");                  // LCD 글자 출력
  lcd.setCursor(0,1);
  lcd.print(temp);
  Serial.println(temp);
  //Serial.println((float)DHT11.temperature,2);

  if(temp >= 18) {                              // 온도 값에 따라 펠티어 동작
    digitalWrite(3,HIGH);
  }else{
    digitalWrite(3,LOW);
  }
  
  delay(2000);
}
