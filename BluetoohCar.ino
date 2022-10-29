#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2); // Rx, Tx

int t = 0;

void setup() {
  
  pinMode(8,OUTPUT);    //left motor forward
  pinMode(9,OUTPUT);    //left motor reverse
  
  pinMode(10,OUTPUT);    //right motor forward
  pinMode(11,OUTPUT);    //left motor reverse

  mySerial.begin(38400);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  
  if(mySerial.available() > 0)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    t = mySerial.read();
    mySerial.println("ACK");
  }

  switch (t)
  {

    case 'F':                             //move forward
        digitalWrite(8, HIGH);
        digitalWrite(10, HIGH);
        break;

    case 'B':                             //move reverse
        digitalWrite(9,HIGH);
        digitalWrite(11,HIGH);
        break;

    case 'R':                             //turn right (left motor rotate forward)
        digitalWrite(8, HIGH);
        break;

    case 'L':                             //turn left (right motor rotate forward)
        digitalWrite(10, HIGH);
        break;

    case 'S':                             //stop all motors
        digitalWrite(8, LOW);
        digitalWrite(10, LOW);
        digitalWrite(9,LOW);
        digitalWrite(11,LOW);
        break;
  }

}
