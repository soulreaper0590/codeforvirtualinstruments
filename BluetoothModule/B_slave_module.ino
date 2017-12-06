#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11);

char state;
const int ledPin = 8;  //the pin your led is connected to
const int buttonPin = 2;  //the pin your button is connected to

int buttonState = 0;

void setup() {

  Serial.begin(9600);
  BTserial.begin(38400);

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {

  if (BTserial.available() > 0) { // Checks whether data is comming from the serial port
    Serial.print("hey");
    state = BTserial.read();
    Serial.println(state);// Reads the data from the serial port
  }
  // Controlling the LED
  Serial.println(state);
  delay(2000);
  
}
