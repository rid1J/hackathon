#include <Wire.h>
#include <Zumo32U4.h>


Zumo32U4ButtonA btnA;
Zumo32U4ButtonB btnB;
Zumo32U4ButtonC btnC;
Zumo32U4LCD lcd;
Zumo32U4Motors motors;

const int maxSpeed = 400;

int speed = 50;
long velocity = (0.0625 * speed);
double rotation  = 0.0;
long distance = 21;

int rotationTime = 5000;

// Movement
void displace(String modifier) {
    if(modifier == "foward") {
      if(distance > 0 && speed <= maxSpeed) {
        while(distance > 0) {
          lcd.print(distance);
          distance = (distance - velocity);
          motors.setSpeeds(speed, speed);
          delay(1000);
        }
        if(distance <= 0) {
          motors.setSpeeds(0, 0);
        }
      }
    }
    if(modifier == "backward") {
      if(distance > 0 && speed <= maxSpeed) {
      while(distance > 0) {
          lcd.print(distance);
          distance = (distance - velocity);
          motors.setSpeeds(-speed, -speed);
          delay(1000);
        }
        if(distance <= 0) {
          motors.setSpeeds(0, 0);
        }
      }
    }
}

// Rotation
void rotate(String mod) {
    if(mod == "clockwise") {
      motors.setSpeeds(0, speed);
      delay(rotationTime);
      motors.setSpeeds(0, 0);
    }
    if(mod == "anticlockwise") {
        motors.setSpeeds(0, speed);
        delay(rotationTime);
        motors.setSpeeds(0, 0);
    }
}

void setup() {
  lcd.clear();
  btnA.waitForButton();
}

void loop() {
  if(btnA.isPressed()) {
    displace("backward");
    distance = 21;
    rotate("anticlockwise");
    displace("foward");
  }
}