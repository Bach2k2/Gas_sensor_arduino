#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(32,16,2);

// initialize the library with the numbers of the interface pins


void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  pinMode(13,OUTPUT); // Redlight
  pinMode(8,OUTPUT);// Piezo buzzer
  pinMode(7,OUTPUT);// Yellow light
  pinMode(6,OUTPUT);// Green light
}

void loop() {
  
  int gas_data;
  gas_data = analogRead(A0);
  lcd.setCursor(0,0);
  lcd.print("Gas :");
  lcd.setCursor(6,00);
  lcd.print(gas_data);
  
  if(gas_data > 800){
  	digitalWrite(13,HIGH);
    digitalWrite(8,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    digitalWrite(8,LOW);
    lcd.setCursor(00,1);
    lcd.print("DANGER");

  }else if(gas_data > 700){
    digitalWrite(6,HIGH);
  	delay(100);
    digitalWrite(6,LOW);
    lcd.setCursor(00,1);
    lcd.print("WARNING");
    
  }else {
    digitalWrite(7,HIGH);
    lcd.setCursor(00,1);
    lcd.print("SAFE");
  }
  
  Serial.println(gas_data);
  delay(100);
  lcd.clear();
 
}
 