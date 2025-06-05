#include <DHT11.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);

DHT11 dht11(2);

// 추후에 센서와 함께 사용할 변수 선언 
int temp, humi;    

void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT);  // 3번핀 릴레이 모듈 (펠티어 모듈)을 출력핀으로 설정
  lcd.init();         // LCD 초기화
  lcd.backlight();    // backlight 켜기

}

void loop() {
  float result = dht11.readTemperatureHumidity(temp, humi);   // DHT11 센서 값을 받아와 chk 변수에 저장
  lcd.setCursor(0,0);                                       // LCD 커서를 0,0으로 초기화
  lcd.print("Current Temp :");                              // LCD 글자 출력
  lcd.setCursor(0,1);
  lcd.print(result);
  Serial.println(result);
  //Serial.println((float)DHT11.temperature,2);

  if(result >= 18) {                              // 온도 값에 따라 펠티어 동작
    digitalWrite(3,HIGH);
  }else{
    digitalWrite(3,LOW);
  }
  
  delay(2000);
}
