int pedal_switch = A0;
int pedal_switch_value = 0;
int BT_switch = A1;
int BT_switch_value = 0;

#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(0, 1); // RX | TX 
int flag = 0; 
const int red_LED = 8; 

void setup() {
  pinMode(pedal_switch, OUTPUT);
  //pinMode(BT_switch, OUTPUT);
  pinMode(red_LED, OUTPUT);
  MyBlue.begin(9600); 
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.print("Initializing...");
  
}

void loop() {
  pedal_switch_value = analogRead(pedal_switch); 
  Serial.print("Pedal Switch: "); Serial.println(pedal_switch_value);
  if (MyBlue.available()) 
   Serial.write(MyBlue.read());
   flag = MyBlue.read(); 
   if (flag == 1) 
   { 
     Serial.println("LED On"); \
     digitalWrite(red_LED, HIGH);
   } 
   else if (flag == 0) 
   { 
     Serial.println("LED Off"); 
   } 
  //BT_switch_value = analogRead(BT_switch); 
  //Serial.print("BT Switch: "); Serial.println(BT_switch_value);
  delay(100);
  
}
