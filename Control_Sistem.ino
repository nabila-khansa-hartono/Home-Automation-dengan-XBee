#include <Keypad.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
const byte ROWS = 4; //empat baris
const byte COLS = 3; //tiga kolom
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};
byte rowPins[ROWS] = {2,3,4,5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  for(int i=2;i<9;i++){
    pinMode(i,OUTPUT);
  }
}

void loop(){
  char key = keypad.getKey();

  if (key != NO_KEY){
    Serial.print(key);
  }
  if(Serial.available()>0){
    int k = Serial.parseInt();
    if(k == 91){
      lcd.setCursor(0,0);
      lcd.print("GAS DETECTED");
    }
    else if(k == 90){
      lcd.setCursor(0,0);
      lcd.print("GAS NOT DETECTED");
    }
    else if(k == 101){
      lcd.setCursor(0,1);
      lcd.print("FLAME DETECTED");
    }
    else if(k == 100){
      lcd.setCursor(0,1);
      lcd.print("FLAME NOT DETECTED");
    }
  }
}
