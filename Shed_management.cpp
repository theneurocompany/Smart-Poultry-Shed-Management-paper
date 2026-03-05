#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);

#include <DHT.h>
DHT dht(2, DHT11);

#define Spray A1
#define Bulb A2
#define Fan A4
#define GasPin A3
#define Buzzer 5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  dht.begin();
  
  pinMode(2, INPUT);
  pinMode(GasPin, INPUT);
  pinMode(Spray, OUTPUT);
  pinMode(Bulb, OUTPUT);
  pinMode(Fan, OUTPUT);
  pinMode(Buzzer, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int t = dht.readTemperature();
  int h = dht.readHumidity();
  lcd.setCursor(0,1);
  lcd.print("T:");
  lcd.setCursor(2,1);
  lcd.print(t);
  lcd.print(char(223));
  lcd.print("C");
  Serial.print('T');
  Serial.print(t);
  
  lcd.setCursor(7,1);
  lcd.print("H:");
  lcd.setCursor(9,1);
  lcd.print(h);
  lcd.print("%");
  Serial.print('H');
  Serial.print(h);

  if (t > 36) {
    lcd.setCursor(0, 0);
    lcd.print("T-H");
    digitalWrite(Fan, HIGH);
    Serial.print('F');// Fan
  }
  else {
    lcd.setCursor(0, 0);
    lcd.print("T-L");
    digitalWrite(Fan, LOW);
    Serial.print('f');// Fan
  }

  if (h > 65) {
    lcd.setCursor(13,1);
    lcd.print("h-H");
    digitalWrite(Bulb, HIGH);
    Serial.print('B');// Bulb
  }
  else {
    lcd.setCursor(13,1);
    lcd.print("h-L");
    digitalWrite(Bulb, LOW);
    Serial.print('b');// Bulb
  }

  int GAS_VALUE = analogRead(GasPin);
  lcd.setCursor(5,0);
  lcd.print("G:");
  lcd.print(GAS_VALUE);
  lcd.print("   ");

  if (GAS_VALUE > 400) {
    lcd.setCursor(12, 0);
    lcd.print("G_H");
    digitalWrite(Spray, LOW);
    Serial.print('G');
  }
  else {
    lcd.setCursor(12, 0);
    lcd.print("G_L");
    digitalWrite(Spray, HIGH);
    Serial.print('g');
  }


  delay(500);

}
