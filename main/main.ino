/*
 *@Aauthor Ridwaan.M.Jawaheer
 *@Description: Hackathon challenge.
 *@Contributor: Mehfouz.M.Foyjoo
 *@Note: PLEASE MODIFY COMMENT ACCORDINGLY WHEN MODIFYING VARIABLE VALUES.
*/

#include <Wire.h>
#include <Zumo32U4.h>


Zumo32U4ButtonA btnA;
Zumo32U4ButtonB btnB;
Zumo32U4ButtonC btnC;
Zumo32U4LCD lcd;
Zumo32U4Motors motors;

const int maxSpeed = 400; // Actual speed: 25cm/s

/*MOVEMENT VARIABLE BEGIN*/
int speed = 50; // Actual speed: 3.125cm/s
long coveredDistance = (0.0625 * speed); // Distance moved in 1s
long finalDistance = 21; // Actual distance: 21cm
/*MOVEMENT VARIABLE END*/

/*MOVEMENT VARIABLE BEGIN*/
int rotationTime = 5000; // Actual time: 5s
/*MOVEMENT VARIABLE END*/

// Movement
void move(String modifier) {
  if(finalDistance > 0 && speed <= maxSpeed) {
      while(finalDistance > 0) {
        finalDistance = (finalDistance - coveredDistance); // Subtract covered distance per second from final distance 
        if(modifier == "foward") {  
          motors.setSpeeds(speed, speed);
        }
        if(modifier == "backward") {
          motors.setSpeeds(-speed, -speed);
        }
        delay(1000);
      }
      if(finalDistance <= 0) {
        motors.setSpeeds(0, 0);
      }
    }
  }
}

// Rotation
void rotate(String mod) {
    if(mod == "clockwise") {
      motors.setSpeeds(speed, 0);
    }
    if(mod == "anticlockwise") {
      motors.setSpeeds(0, speed);
    }
    delay(rotationTime);
    motors.setSpeeds(0, 0);
}

void setup() {
  lcd.clear();
}

void loop() {
  if(btnA.isPressed()) {
    move("backward");
    finalDistance = 21;
    rotate("anticlockwise");
    move("foward");
  }
}