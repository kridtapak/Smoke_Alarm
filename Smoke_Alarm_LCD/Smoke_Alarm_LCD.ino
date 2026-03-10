#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int smokeSensor = A0;
int buzzer = 8;

int smokeValue;

void setup()
{
  pinMode(smokeSensor, INPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);

  lcd.setCursor(0,0);
  lcd.print("Smoke Detector");
  lcd.setCursor(0,1);
  lcd.print("Warming Sensor");
  
  delay(20000);   // MQ sensor warm up
  lcd.clear();
}

void loop()
{
  smokeValue = analogRead(smokeSensor);

  Serial.print("Smoke Value: ");
  Serial.println(smokeValue);

  lcd.setCursor(0,0);
  lcd.print("Smoke:");
  lcd.print(smokeValue);
  lcd.print("   ");

  lcd.setCursor(0,1);

  if(smokeValue < 300)
  {
    lcd.print("LEVEL: LOW    ");
    noTone(buzzer);
  }

  else if(smokeValue >= 300 && smokeValue < 500)
  {
    lcd.print("LEVEL: MEDIUM ");
    tone(buzzer,1000);
  }

  else
  {
    lcd.print("LEVEL: HIGH   ");
    tone(buzzer,1500);
  }

  delay(500);
}