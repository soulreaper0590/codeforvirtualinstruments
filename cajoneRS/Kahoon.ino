/*Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/

// defines pins numbers
const int trigPin =12;
const int echoPin =13;
int initDist=0;
// defines variables
long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
// Clears the trigPin
/*

 digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
initDist= duration*0.034/2;
Serial.println(initDist);
*/

}
char change;

void loop() {
  //initDist=43;
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
//Serial.println(distance);
// Calculating the distance
distance= duration*0.034/2;

if (distance>=42)
  {change='A';}
if(distance<=12&&change=='A')
  {Serial.println('L');
  change='B';}
else if(distance>12&&distance<=40&&change=='A')
  {Serial.println('M');
  change='B';}
/*else if(distance>24&&distance<=35&&change=='A')
  {Serial.println('H');
  change='B';}
*/
  delay(100);

// Prints the distance on the Serial Monitor
//Serial.print("Distance: ");
//Serial.println(distance);

}
