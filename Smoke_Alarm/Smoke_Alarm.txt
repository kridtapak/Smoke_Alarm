int smokeA0 = A0;
int buzzer = 8;  
int led = 7;
int sensorValue;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);

  Serial.println("Sensor warming up...");
  delay(30000);   // วอร์ม 30 วินาที
}

void loop() {

  sensorValue = analogRead(smokeA0);

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  if(sensorValue > 500)   // ปรับค่า threshold
  {
    Serial.println("Smoke detected!");
    tone(buzzer, 1000);
    digitalWrite(led, HIGH);
  }
  else
  {
    Serial.println("No smoke");
    noTone(buzzer);
    digitalWrite(led, LOW);
  }

  delay(500);
}