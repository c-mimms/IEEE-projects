/* 

This code is built on David Mellis's Ping sensor code to show a very basic robot behavior.

Code was used in Arduino Tutorials at the ERAU IEEE Student Branch.



 This sketch reads a PING))) ultrasonic rangefinder and returns the
 distance to the closest object in range. To do this, it sends a pulse
 to the sensor to initiate a reading, then listens for a pulse 
 to return.  The length of the returning pulse is proportional to 
 the distance of the object from the sensor.
 
 The circuit:
 	* +V connection of the PING))) attached to +5V
 	* GND connection of the PING))) attached to ground
 	* SIG connection of the PING))) attached to digital pin 7
 
 http://www.arduino.cc/en/Tutorial/Ping
 
 created 3 Nov 2008
 by David A. Mellis
 modified 30 Aug 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 */

// this constant won't change.  It's the pin number
// of the sensor's output:
#include <NewPing.h>

#define TRIGGER_PIN  5  // Arduino pin tied to trigger pin on ping sensor.
#define ECHO_PIN     5  // Arduino pin tied to echo pin on ping sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define LEFTIR A5
#define RIGHTIR A4

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

unsigned int pingSpeed = 50; // How frequently are we going to send out a ping (in milliseconds). 50ms would be 20 times a second.
unsigned long pingTimer;     // Holds the next ping time.
int lastping = 1000;
const int pingPin = 5;
const int BDir = 12;
const int ADir = 13;
const int ASpeed = 10;
const int BSpeed = 9;
int state = 1;
long lastTime;

void setup() {
  // initialize serial communication:
  pingTimer = millis(); // Start now.
  pinMode(ADir, OUTPUT);
  pinMode(BDir, OUTPUT);
  pinMode(ASpeed, OUTPUT);
  pinMode(BSpeed, OUTPUT);
  pinMode(LEFTIR, INPUT);
  pinMode(RIGHTIR, INPUT);
  digitalWrite(ASpeed, LOW);
  digitalWrite(BSpeed, LOW);
  digitalWrite(LEFTIR, LOW);
  digitalWrite(RIGHTIR, LOW);
  Serial.begin(9600);
}

void loop()
{ 
  int left = analogRead(LEFTIR);
  int right = analogRead(RIGHTIR);
  Serial.print("Left IR = ");
  //Serial.print( temp );
  Serial.print(" and Right IR = " );
  //Serial.println(temp2) ;  
  if(left >600){
    turnRight(200); 
  }
  else if(right >700){
    turnLeft(200); 
  }
  else{
    goForward(150);
  }
  
}


void echoCheck() { // Timer2 interrupt calls this function every 24uS where you can check the ping status.
  // Don't do anything here!
  if (sonar.check_timer()) { 
    lastping = sonar.ping_result / US_ROUNDTRIP_CM; // Ping returned, uS result in ping_result, convert to cm with US_ROUNDTRIP_CM.

  }
}

void drive(){
  goForward(200);
  if(lastping <15 && lastping != 0){
    state = 2;
  }
}


void turn(){
  turnRight(200);
  delay(1000);
  state = 1;


}


void goForward(int speed){

  digitalWrite(ADir,HIGH);
  digitalWrite(BDir,HIGH);
  analogWrite(ASpeed,speed);
  analogWrite(BSpeed,speed);
}
void setSpeed(int speed){

  analogWrite(ASpeed,speed);
  analogWrite(BSpeed,speed);
}
void goBackwards(int speed){

  digitalWrite(ADir,LOW);
  digitalWrite(BDir,LOW);
  analogWrite(ASpeed,speed);
  analogWrite(BSpeed,speed);
}
void turnLeft(int speed){

  digitalWrite(ADir,LOW);
  digitalWrite(BDir,HIGH);
  analogWrite(ASpeed,speed);
  analogWrite(BSpeed,speed);
}
void turnRight(int speed){

  digitalWrite(ADir,HIGH);
  digitalWrite(BDir,LOW);
  analogWrite(ASpeed,speed);
  analogWrite(BSpeed,speed);
}
void stopMotors(){

  analogWrite(ASpeed,0);
  analogWrite(BSpeed,0);
  digitalWrite(ADir,HIGH);
  digitalWrite(BDir,LOW);
}



