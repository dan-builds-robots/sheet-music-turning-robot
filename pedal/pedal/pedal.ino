// PORT 1301

int switchPin = A0;
int prevValue = 1;
int ledPin = 9;

void setup() {
  
  Serial.begin(38400);

  pinMode(ledPin, OUTPUT);

  // set up the pedal switch
  pinMode(switchPin, INPUT_PULLUP);

}

void loop() {

  int value = digitalRead(switchPin);
  if(value==0){
    digitalWrite(ledPin, HIGH);
    Serial.write("0");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.write("1");
  }

}
