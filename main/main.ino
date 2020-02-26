  /*
  *@Author Ridwaan.M.Jawaheer
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
  int speed = 200; // Actual speed: 9.375cm/s
  long coveredDistance = (0.0625 * speed); // Distance moved in 1s
  long finalDistance = 0; // Actual distance: 21cm
  /*MOVEMENT VARIABLE END*/

  /*MOVEMENT VARIABLE BEGIN*/
  int rotationTime = 0; // Actual time: 0.5s
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

  // Rotation
  void rotate(String mod) {
      if(mod == "clockwise") {
        motors.setSpeeds(speed, -speed);
      }
      if(mod == "anticlockwise") {
        motors.setSpeeds(-speed, speed);
      }
      delay(rotationTime);
      motors.setSpeeds(0, 0);
  }

  void setup() {
    lcd.clear();
  }

  void loop() {
    if(btnA.isPressed()) {
      delay(2000);
    // 1 - 2
      finalDistance = 12;
      move("foward");

    // 2
      rotationTime = 320;
      rotate("anticlockwise");

    // 2-3
      speed = 100;
      finalDistance = 1;
      move("foward");


    // 3
      speed = 200;
      rotationTime = 320;
      rotate("anticlockwise");
    
    // 3-4
      finalDistance = 12;
      move("foward");

    // 4
      rotationTime = 495;
      rotate("anticlockwise");

    // 4-5
      speed = 80;
      finalDistance = 1;
      move("foward");

    // 5
      speed = 200;
      rotationTime = 340;
      rotate("anticlockwise");

    // 5-6
      speed = 145;
      finalDistance = 4;
      move("foward");

    // 6
      speed = 200;
      rotationTime = 650;
      rotate("clockwise");

    // 7-8
      speed = 160;
      finalDistance = 4;
      move("foward");

    // 8
      speed = 200;
      rotationTime = 400;
      rotate("anticlockwise");

    // 8-9
      speed = 100;
      finalDistance = 4;
      move("foward");
    }
  }