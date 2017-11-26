/*Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/

// defines pins numbers
const int trigPin =11;
const int echoPin =12;
int initDist=0;
// defines variables
long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
// Clears the trigPin
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


}

void loop() {
  initDist=43;
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
char change;
if (distance>=40)
  change='A';
else if(distance<=8&&change=='A')
  {Serial.println('L');
  change=='B';}
else if(distance>8&&distance<=18&&change=='A')
  {Serial.println('M');
  change=='B';}
else if(distance>18&&distance<35&&change=='A')
  {Serial.println('H');
  change=='B';}

  delay(50);

// Prints the distance on the Serial Monitor
//Serial.print("Distance: ");
//Serial.println(distance);

}
