
const int trigpin = 10;  //Trigpin  UV mesafe sensörü için
const int echopin = 9;   //Echopin  UV mesafe sensörü için
const int gnd = 8;       //İki ledin de topraklaması
const int red = 7;       //Kırmızı LED
const int green = 6;     //Yeşil Led

long duration; 

#include <LiquidCrystal.h>
int calculateDistance()  //Mesafeyi hesaplama fonksiyonu
{
  
  
  digitalWrite(trigpin,1);
  delayMicroseconds(2);
  digitalWrite(trigpin,1);
  delayMicroseconds(10);
  digitalWrite(trigpin,0);
  float duration = pulseIn(echopin,1);
  Serial.println(duration);
  
  
  float distance = duration * 0.01723;
  float heightofman=336.5-distance;
  Serial.println(heightofman);
  return (int)heightofman;
}

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("HESAPLANIYOR..");
  
  
  pinMode(trigpin , 1);
  pinMode(echopin , 0);
  pinMode(gnd,1);
  pinMode(green,1);
  pinMode(red,1);
  digitalWrite(gnd,0);
  pinMode(13,0);
  Serial.begin(3600);
}

void loop() {
  
  lcd.setCursor(0, 0);
  int distance = calculateDistance();
  lcd.print(distance);
  if(distance >= 100)
  {  
  	lcd.setCursor(3,0);
    lcd.print("cm");
    delay(100);
    lcd.clear();
  }
  else
  {
    
    lcd.setCursor(2,0);
    lcd.print("cm");
    delay(100);
    lcd.clear();
  }
  
  if(distance > 150)
  {
    digitalWrite(green,1);
    digitalWrite(red,0);
  }
  else if (distance <= 150)
  {
    digitalWrite(green,0);
    digitalWrite(red,1);
  }
}

