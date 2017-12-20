 const int pingPin1 = 9;
 const int pingPin2 = 11;
 void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  //code for ping part
  long duration1,duration2, inches1,inches2, cm1,cm2,f1,f2,f3,f4;
  pinMode(pingPin1, OUTPUT);
  digitalWrite(pingPin1, LOW); //give a short low impulse before hand to ensure clean high pulse.
  delayMicroseconds(2);  //the ping is triggered by a short impulse of 2 or more microseconds
  digitalWrite(pingPin1, HIGH); //the same piun is used to read the signal   
  delayMicroseconds(5);  //max time to sending and receiving its echo of an object
  digitalWrite(pingPin1, LOW);
  pinMode(10, INPUT);
  duration1 = pulseIn(10, HIGH);
  
   inches1 = microsecondsToInches(duration1);
   cm1 = microsecondsToCentimeters(duration1);
  //Serial.print(cm1);
  //Serial.println("cm PING1");
 //for ping 2

  pinMode(pingPin2, OUTPUT);
  digitalWrite(pingPin2, LOW); //give a short low impulse before hand to ensure clean high pulse.
  delayMicroseconds(2);  //the ping is triggered by a short impulse of 2 or more microseconds
  digitalWrite(pingPin2, HIGH); //the same piun is used to read the signal   
  delayMicroseconds(5);  //max time to sending and receiving its echo of an object
  digitalWrite(pingPin2, LOW);
  pinMode(12, INPUT);
  duration2 = pulseIn(12, HIGH);
  
   inches2 = microsecondsToInches(duration2);
   cm2 = microsecondsToCentimeters(duration2);
 // Serial.print(cm2);
 // Serial.println("cm PING2");
f1=analogRead(A4);
Serial.println(f1);
//Serial.println("index finger");
f2=analogRead(A3);
//Serial.println(f2);
//Serial.println("middle finger");
f3=analogRead(A2);
//Serial.println(f3);
//Serial.println("ring finger");
f4=analogRead(A1);
//Serial.println(f4);
//Serial.println("little finger");


  
  delay(100);
}
  long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
   }

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
   }
 
   
//string1=digitalRead(4);
//string2=analogRead(5);
 
/*//stretch=analogRead(6);
if(string1<700)
  {
    //digitalWrite(4,HIGH);
    if (finger(f1)==1)
      Serial.println('z');
    else if(finger(f2)==1)
      Serial.println('x');
    else if(finger(f3)==1)
      Serial.println('c');
    else if(finger(f4)==1)
      Serial.println('v');
  }   
else if(string2<700)
{
  if (finger(f1)==1)
      Serial.println('a');
    else if(finger(f2)==1)
      Serial.println('s');
    else if(finger(f3)==1)
      Serial.println('d');
    else if(finger(f4)==1)
      Serial.println('f');
  }   
//digitalWrite(4,LOW);
delay(100);

}

int finger(int f)
{
    if (f<300)
      return 1;
    else
      return 0;*/




