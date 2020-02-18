#include <Wire.h>
#include <Zumo32U4.h>


Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
Zumo32U4ButtonC buttonC;
Zumo32U4LCD lcd;

void setup() {
  // put your setup code here, to run once:

  lcd.clear();
  lcd.print(F("Press A for challenge 1, Press B for challenge 2, Press C for challenge 3"));
  buttonA.waitForButton();
  buttonB.waitForButton();
  buttonC.waitForButton();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  lcd.clear();

  if (buttonA.isPressed()) {
    lcd.print(F("Challenge 1..."));
  }

  if (buttonB.isPressed()) {
    lcd.print(F("Challenge 2..."));
  }

  if (buttonC.isPressed()) {
    lcd.print(F("Challenge 3..."));
  }
}
