#define ultraSonicPin 13 //ultrasound signal pin

void setup() {
  Serial.begin(9600);
  // pinModfe(UltraSonicPin,OUTPUT);
  

}
unsigned long ping()
{
  unsigned long echo = 0;
  unsigned long ultrasoundValue = 0;
  pinMode(ultraSonicPin,OUTPUT);// Switch signalpin to output
  digitalWrite(ultraSonicPin,LOW);// send low pulse
  delayMicroseconds(5);// wait for 5 microseconds
  digitalWrite(ultraSonicPin,HIGH);// send high pulse
  delayMicroseconds(5);
  digitalWrite(ultraSonicPin,LOW);//HoldOff
  pinMode(ultraSonicPin,INPUT_PULLUP);//switch signalpin to input
  // digitalWrite(ultraSonicPin,HIGH);//Turn on pullup resistor
  // please note that a pulseIN has a 1sec timeout, which may
  //not be desirable. Depending on your sensor specs, you
  //can likely bound the time like this--macmerlin
  //echo = pulseIN(ultraSonicPin, HIGH,38000)
  echo= pulseIN(ultraSonicPin,HIGH);//Listen to echo
  Serial.print("EchoTime(us): ");
  Serial.print(echo);
  Serial.print(" ");
  ultrasoundValue = (echo*0.0165);// convert to cm
  //ultrasoundValue = (echo/58.138);//* .39//convert to CM then to inches
  return untrasoundValue;
  
  
}

void loop() {
  int x = 0;
  x = ping();

  Serial.println(x);
  delay(250);// delay 1/4 seconds.

}
