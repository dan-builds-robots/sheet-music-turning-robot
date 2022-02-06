// PORT  1401

#include <Servo.h>

int delayPeriod = 1000; 
int servoPinPageTurning = 3;
int servoPinLinearActuator = 6;
int servoPos = 0;
Servo pageTurningServo;
Servo linearActuatorServo;

int prevValue = 1;

void setup() {

  Serial.begin(38400);

  // setting up the servos
  pageTurningServo.attach(servoPinPageTurning);
  linearActuatorServo.attach(servoPinLinearActuator);

  // reset positioning of page turning servo
  pageTurningServo.write(0);

  // no motion for servo
  linearActuatorServo.write(90);

}

void loop() {

  if (Serial.available() > 0) {
    
    int value = digitalRead(Serial.read());
  
    if (value == 0 && prevValue == 1) {

      Serial.println("pedal pressed");

      // move the page flipper downwards
      linearActuatorServo.write(180);
      delay(0.36 * 1.0 * 1000);
      linearActuatorServo.write(90);
      
      // wait for 1 second
      delay(delayPeriod);

      // turn the page, from 1 to 180
      for (int i = 1; i <= 180; i++) {
        pageTurningServo.write(i);
        delay(20);
      }
      // pageTurningServo.write(180);
      
      // wait for 1 second
      delay(delayPeriod);

      // move the page flipper upwards
      linearActuatorServo.write(0);
      delay(0.36 * 1.0 * 1000);
      linearActuatorServo.write(90);

      // wait for 1 second
      delay(delayPeriod);
      
      // turn the page back, from 179 to 0
      for (int i = 179; i >= 0; i--) {
        pageTurningServo.write(i);
        delay(20);
      }
      // pageTurningServo.write(0);

    }

    prevValue = value;

  }

}
