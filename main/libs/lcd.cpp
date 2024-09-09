#include <LiquidCrystal.h>
#include "pins.h"

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(RS_PIN, E_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

void setupLCD(){
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void showMessage(char msg[], uint8_t line){
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, line);
  // print the number of seconds since reset:
  lcd.print(msg);
}

void clearLCD(){
    lcd.clear();
}