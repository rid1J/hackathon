#include <Wire.h>
#include <Zumo32U4.h>


Zumo32U4ButtonA btnA;
Zumo32U4ButtonB btnB;
Zumo32U4ButtonC btnC;
Zumo32U4LCD lcd;

// Calculate battery life
long readVcc() {
  long result;
  // Read 1.1V reference against AVcc
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA,ADSC));
  result = ADCL;
  result |= ADCH<<8;
  result = 1126400L / result; // Back-calculate AVcc in mV
  return (60000 - result) / 1000 * 100;
}

void startChallengeOne() {
  // Draw Accenture logo
  
}

void startChallengeTwo() {
  // Follow path

}

void startChallengeThree() {
  // Complete race track

}

void setup() {

}

void loop() {

  lcd.clear();
  lcd.println( readVcc(), DEC );
  delay(1000);

  if(btnA.isPressed()) {
    startChallengeOne();
  }

  if(btnB.isPressed()) {
    startChallengeTwo();
  }

  if(btnC.isPressed()) {
    startChallengeThree();
  }
}