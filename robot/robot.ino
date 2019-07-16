#define ultraSonicPin 4 //ultrasound signal pin T
#define ultraSonicPinR 5 //ultrasound signal pin R

  int MRPin1=10;
  int MRPin2=11;

  int MLPin1=9;
  int MLPin2=8;

   
void setup() {
  pinMode(MRPin1,OUTPUT);
  pinMode(MRPin2,OUTPUT);
  pinMode(MLPin1,OUTPUT);
  pinMode(MLPin2,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(3,OUTPUT);
  digitalWrite(6,LOW);
  digitalWrite(3,HIGH);
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
  pinMode(ultraSonicPinR,INPUT_PULLUP);//switch signalpin to input
  // digitalWrite(ultraSonicPin,HIGH);//Turn on pullup resistor
  // please note that a pulseIN has a 1sec timeout, which may
  //not be desirable. Depending on your sensor specs, you
  //can likely bound the time like this--macmerlin
  //echo = pulseIn(ultraSonicPin, HIGH,38000)
  echo= pulseIn(ultraSonicPinR,HIGH);//Listen to echo
  Serial.print("EchoTime(us): ");
  Serial.print(echo);
  Serial.print(" ");
  ultrasoundValue = (echo*0.0165);// convert to cm
  //ultrasoundValue = (echo/58.138);//* .39//convert to CM then to inches
  return ultrasoundValue;
}



void forward()
{
  digitalWrite(MRPin1,HIGH);
  digitalWrite(MRPin2,LOW);
  digitalWrite(MLPin1,HIGH);
  digitalWrite(MLPin2,LOW);
}

void stop()
{
  digitalWrite(MRPin1,LOW);
  digitalWrite(MRPin2,LOW);
  digitalWrite(MLPin1,LOW);
  digitalWrite(MLPin2,LOW);
}

void backward()
{
  digitalWrite(MRPin1,LOW);
  digitalWrite(MRPin2,HIGH);
  digitalWrite(MLPin1,LOW);
  digitalWrite(MLPin2,HIGH);
}

void right()
{
  digitalWrite(MRPin1,LOW);
  digitalWrite(MRPin2,HIGH);
  digitalWrite(MLPin1,HIGH);
  digitalWrite(MLPin2,LOW);
}

void left()
{
  digitalWrite(MRPin1,HIGH);
  digitalWrite(MRPin2,LOW);
  digitalWrite(MLPin1,LOW);
  digitalWrite(MLPin2,HIGH);  
}

void loop() {
  int d = ping();
  if(d>15)
  {
    forward();
  }
  else
  {
    search();
  }  
}

void search()
{
  int lDis = 0;
  int rDis = 0;
  int d = 500;
  left();
  delay(5);
  while(rDis<20 || lDis<20)
  { 
    right();
    delay(d);    
    stop();
    rDis = ping();
    left();
    delay(d);
    stop();
    lDis = ping();
    d = d + d/2;
    if(d > 2200) d = 2200;    
  }
  if(rDis>lDis)
  {
    right();
    delay(d/1.5);
  }  
}

