const int out=12;
const int in=13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(out,OUTPUT);
  pinMode(in,INPUT);

}

void loop() {
  // put your main code here,to run repeatedly:
  long dur;
  long dis;

  digitalWrite(out,LOW);
  delayMicroseconds(2);

  digitalWrite(out,HIGH);
  delayMicroseconds(10);
  digitalWrite(out,LOW);
  long int true_cm;
  dur=pulseIn(in,HIGH);
  true_cm = 2.54*dur;
  true_cm = true_cm/100;
  
  Serial.println(String(dur));
  if(true_cm>50){
  Serial.println(String("away keystroke(nothing)"));
  }
  else if(true_cm<38){
  Serial.println(String("this is the base keysrokes(base)"));
  }
  else{
  Serial.println(String("this the uppermost part keysrtoke(theupper)"));
  }
  Serial.println(String("this is in cm")+ true_cm);

  delay(1000);
}
