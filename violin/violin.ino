void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
string1=analogRead(4);
string2=analogRead(5);
f1=analogRead(0);
f2=analogRead(1);
f3=analogRead(2);
f4=analogRead(3);
stretch=analogRead(6);
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
      return 0;
}


