#include <Servo.h>
// #include <ezButton.h>

// ezButton limitSwitch(7);

int delayPeriod = 1000;
int servoPinPageTurning = 3;
int servoPinLinearActuator = 6;
int servoPos = 0;
int activateButton = A0;
Servo pageTurningServo;
Servo linearActuatorServo;

int prevValue = 1;

void setup() {

  Serial.begin(9600);

  pinMode(activateButton, INPUT_PULLUP);
  pageTurningServo.attach(servoPinPageTurning);
  linearActuatorServo.attach(servoPinLinearActuator);

  // reset positioning of page turning servo
  pageTurningServo.write(0);

  // no motion for servo
  linearActuatorServo.write(90);

}

void loop() {

  int value = digitalRead(activateButton);
  
  if (value == 0 && prevValue == 1) {

    Serial.println("pedal pressed");

    // move the page flipper downwards
    linearActuatorServo.write(180);
    delay(0.36 * 1.0 * 1000);
    linearActuatorServo.write(90);
    
    // wait for 1 second
    delay(delayPeriod);

    // turn the page
    pageTurningServo.write(180);
    
    // wait for 1 second
    delay(delayPeriod);

    // move the page flipper upwards
    linearActuatorServo.write(0);
    delay(0.36 * 1.0 * 1000);
    linearActuatorServo.write(90);

    // wait for 1 second
    delay(delayPeriod);
    
    // turn the page back
    pageTurningServo.write(0);

  }

  prevValue = value;

}
