#include <LiquidCrystal.h>

LiquidCrystal lcd(8,7,6,5,4,3);
int buttonUp = 9;
int buttonDown = 10;
int buttonEnter = 11;
int led = 12;
int position = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(buttonUp, INPUT);
  pinMode(buttonDown, INPUT);
  pinMode(buttonEnter, INPUT);
  pinMode (led,OUTPUT);
  updateScreen();
}

void loop() {
  if(digitalRead(buttonUp) == HIGH) {
    delay(50); // debounce delay
    if(position == 0) {
      position = 1;
    }
    else {
      position = 0;
    }
    updateScreen();
  }
  if(digitalRead(buttonDown) == HIGH) {
    delay(50); // debounce delay
    if(position == 1) {
      position = 0;
    }
    else {
      position = 1;
    }
    updateScreen();
  }
  if(digitalRead(buttonEnter) == HIGH) {
    delay(50); // debounce delay
    if(position == 0) {
       digitalWrite(led,HIGH);
    }
 
    
  }

  if(digitalRead(buttonEnter) == HIGH) {
    delay(50); // debounce delay
    if(position == 1) {
       digitalWrite(led,LOW);
      
    }
  }
}

void updateScreen() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" Led ac");
  if(position == 0) {
    lcd.setCursor(0, 0);
    lcd.print(".");
    lcd.display();
    
  }

  lcd.setCursor(0,1);
  if(position == 1) {
    lcd.print(".");
    lcd.display();
  }
  else {
    lcd.print(" ");
  }

  lcd.print(" Led kapat ");
  if(position == 1) {
    lcd.setCursor(0, 1);
    lcd.print(".");
    lcd.display();
  
  }
 
  
}
