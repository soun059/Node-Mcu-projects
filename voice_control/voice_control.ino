
#include <SoftwareSerial.h>

SoftwareSerial BT(0, 1); //TX, RX respetively
String readvoice;

void setup() {
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);

}
//-----------------------------------------------------------------------// 
void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = BT.read(); //Conduct a serial read
  readvoice += c; //build the string- "forward", "reverse", "left" and "right"
  } 
  if (readvoice.length() > 0) {
    Serial.println(readvoice);

  if(readvoice == "*forward#")
  {
    digitalWrite(4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    delay(100);
  }

  else if(readvoice == "*back#")
  {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7,HIGH);
    delay(100);
  }

  else if (readvoice == "*left#")
  {
    digitalWrite (4,HIGH);
    digitalWrite (5,LOW);
    digitalWrite (6,LOW);
    digitalWrite (7,LOW);
   delay (800);
      digitalWrite(4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    delay(100);
  
  }

 else if ( readvoice == "*right#")
 {
   digitalWrite (4, LOW);
   digitalWrite (5, HIGH);
   digitalWrite (6, LOW);
   digitalWrite (7, LOW);
   delay (800);
      digitalWrite(4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    delay(100);
 }

 else if (readvoice == "*stop#")
 {
   digitalWrite (4, LOW);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   digitalWrite (7, LOW);
   delay (100);
 }
 else if (readvoice == "*keep watch in all direction#")
 {
   digitalWrite (4, HIGH);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   digitalWrite (7, LOW);
   delay (100);
 }
  else if (readvoice == "*show me Garba#")
 {
 digitalWrite (4, LOW);
   digitalWrite (5, HIGH);
   digitalWrite (6, LOW);
   digitalWrite (7, LOW);
   delay (400);
      digitalWrite(4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    delay(600);
    digitalWrite (4, LOW);
   digitalWrite (5, HIGH);
   digitalWrite (6, HIGH);
   digitalWrite (7, LOW);
   delay (500);
   digitalWrite (4, HIGH);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   digitalWrite (7, HIGH);
   delay (500);

digitalWrite (4, LOW);
   digitalWrite (5, HIGH);
   digitalWrite (6, LOW);
   digitalWrite (7, LOW);
   delay (400);
      digitalWrite(4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    delay(600);
    digitalWrite (4, LOW);
   digitalWrite (5, HIGH);
   digitalWrite (6, HIGH);
   digitalWrite (7, LOW);
   delay (500);
   digitalWrite (4, HIGH);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   digitalWrite (7, HIGH);
   delay (500);digitalWrite (4, LOW);
   digitalWrite (5, HIGH);
   digitalWrite (6, LOW);
   digitalWrite (7, LOW);
   delay (400);
      digitalWrite(4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    delay(600);
    digitalWrite (4, LOW);
   digitalWrite (5, HIGH);
   digitalWrite (6, HIGH);
   digitalWrite (7, LOW);
   delay (500);
   digitalWrite (4, HIGH);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   digitalWrite (7, HIGH);
   delay (500);digitalWrite (4, LOW);
   digitalWrite (5, HIGH);
   digitalWrite (6, LOW);
   digitalWrite (7, LOW);
   delay (400);
      digitalWrite(4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    delay(600);
    digitalWrite (4, LOW);
   digitalWrite (5, HIGH);
   digitalWrite (6, HIGH);
   digitalWrite (7, LOW);
   delay (500);
   digitalWrite (4, HIGH);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   digitalWrite (7, HIGH);
   delay (500);digitalWrite (4, LOW);
   digitalWrite (5, HIGH);
   digitalWrite (6, LOW);
   digitalWrite (7, LOW);
   delay (400);
      digitalWrite(4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    delay(600);
    digitalWrite (4, LOW);
   digitalWrite (5, HIGH);
   digitalWrite (6, HIGH);
   digitalWrite (7, LOW);
   delay (500);
   digitalWrite (4, HIGH);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   digitalWrite (7, HIGH);
   delay (500);digitalWrite (4, LOW);
   digitalWrite (5, HIGH);
   digitalWrite (6, LOW);
   digitalWrite (7, LOW);
   delay (400);
      digitalWrite(4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    delay(600);
    digitalWrite (4, LOW);
   digitalWrite (5, HIGH);
   digitalWrite (6, HIGH);
   digitalWrite (7, LOW);
   delay (500);
   digitalWrite (4, HIGH);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   digitalWrite (7, HIGH);
   delay (500);digitalWrite (4, LOW);
   digitalWrite (5, HIGH);
   digitalWrite (6, LOW);
   digitalWrite (7, LOW);
   delay (400);
      digitalWrite(4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    delay(600);
    digitalWrite (4, LOW);
   digitalWrite (5, HIGH);
   digitalWrite (6, HIGH);
   digitalWrite (7, LOW);
   delay (500);
   digitalWrite (4, HIGH);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   digitalWrite (7, HIGH);
   delay (500);digitalWrite (4, LOW);
   digitalWrite (5, HIGH);
   digitalWrite (6, LOW);
   digitalWrite (7, LOW);
   delay (400);
      digitalWrite(4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    delay(600);
    digitalWrite (4, LOW);
   digitalWrite (5, HIGH);
   digitalWrite (6, HIGH);
   digitalWrite (7, LOW);
   delay (500);
   digitalWrite (4, HIGH);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   digitalWrite (7, HIGH);
   delay (500);
 }


 readvoice="";}} //Reset the variable
