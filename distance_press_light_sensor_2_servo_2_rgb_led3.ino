/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/
// *distance sensor*
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

// *servo hand*
#include <Servo.h>
Servo myservo1;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos1 = 0;    // variable to store the servo position

// *servo head*
Servo myservo2;  // create servo object to control a servo
int pos2 = 0;    // variable to store the servo position

// *eye left*
int redleftpin= 5;
int greenleftpin = 6;
int blueleftpin = 8;

// *eye right*
int redrightpin= 9;
int greenrightpin = 11;
int bluerightpin = 13;

// *presssensor*
int presssensorPin = A0;
int presssensorValue = 0;

// *lightsensor*
int lightsensorPin = A1;
int lightsensorValue = 0;

void setup() {
  // *servo hand*
  myservo1.attach(4);  // attaches the servo head on pin 4 to the servo object

//  *servo head*
  myservo2.attach(7);  // attaches the servo hand on pin 7 to the servo object

  // *distance sensor*
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");

  // *eye left*
   pinMode(redleftpin, OUTPUT);
  pinMode(greenleftpin, OUTPUT);
  pinMode(blueleftpin, OUTPUT);

   // *eye right*
   pinMode(redrightpin, OUTPUT);
  pinMode(greenrightpin, OUTPUT);
  pinMode(bluerightpin, OUTPUT);
}

void loop() {
  // *distance sensor* //*light sensor* //*press sensor* //*servo hand* //*night*
  if (distance < 10 && lightsensorValue < 100 && presssensorValue < 200) {
  for (pos1 = 45; pos1 >= 0; pos1 -= 1) {
    myservo1.write(pos1);              // tell servo to go to position in variable 'pos'

    // *eyes*
    analogWrite(redleftpin, 255);
  analogWrite(greenleftpin, 255);
  analogWrite(blueleftpin, 125);

  analogWrite(redrightpin, 255);
  analogWrite(greenrightpin, 255);
  analogWrite(bluerightpin, 125);
    delay(10);  
    }                     // waits 15ms for the servo to reach the position
  
  // *servo hand*
  for (pos1 = 0; pos1 <= 90; pos1 += 1) {
    myservo1.write(pos1); 
   
    // *eyes*
    analogWrite(redleftpin, 255);
  analogWrite(greenleftpin, 255);
  analogWrite(blueleftpin, 125);

  analogWrite(redrightpin, 255);
  analogWrite(greenrightpin, 255);
  analogWrite(bluerightpin, 125);
    delay(10);                       // waits 15ms for the servo to reach the position
  } }

  // *distance sensor* //*light sensor* //*press sensor* //*servo hand* //*day*
  if (distance < 10 && lightsensorValue > 100 && presssensorValue < 200) {
  for (pos1 = 45; pos1 >= 0; pos1 -= 1) {
    myservo1.write(pos1);              // tell servo to go to position in variable 'pos'

    // *eyes*
    analogWrite(redleftpin, 255);
  analogWrite(greenleftpin, 255);
  analogWrite(blueleftpin, 125);

  analogWrite(redrightpin, 255);
  analogWrite(greenrightpin, 255);
  analogWrite(bluerightpin, 125);
    delay(10);  
    }                     // waits 15ms for the servo to reach the position
  
  // *servo hand*
  for (pos1 = 0; pos1 <= 90; pos1 += 1) {
    myservo1.write(pos1); 

    // *eyes*
    analogWrite(redleftpin, 255);
  analogWrite(greenleftpin, 255);
  analogWrite(blueleftpin, 125);

  analogWrite(redrightpin, 255);
  analogWrite(greenrightpin, 255);
  analogWrite(bluerightpin, 125);
    delay(10);                       // waits 15ms for the servo to reach the position
  } }
  
  //*distance sensor* //*light sensor* //*press sensor* //*day*
   else if (distance > 10 && lightsensorValue > 100 && presssensorValue < 200) {

    // *servo hand*
    pos1 = 45;
    myservo1.write(pos1);

    // *servo head*
    pos2 = 45;
    myservo2.write(pos2);

    // *eyes*
    analogWrite(redleftpin, 0);
  analogWrite(greenleftpin, 0);
  analogWrite(blueleftpin, 0);

  analogWrite(redrightpin, 0);
  analogWrite(greenrightpin, 0);
  analogWrite(bluerightpin, 0);
    
    }
    
//*distance sensor* //*light sensor* //*press sensor* //*night*
    else if (distance > 10 && lightsensorValue < 100 && presssensorValue < 200) {

    // *servo hand*
    pos1 = 45;
    myservo1.write(pos1);

    // *servo head*
    pos2 = 45;
    myservo2.write(pos2);

    // *eyes*
    analogWrite(redleftpin, 0);
  analogWrite(greenleftpin, 0);
  analogWrite(blueleftpin, 255);

  analogWrite(redrightpin, 0);
  analogWrite(greenrightpin, 0);
  analogWrite(bluerightpin, 255);
    
    }

    else if(presssensorValue > 200) {
    // *servo hand*
      for (pos1 = 45; pos1 >= 0; pos1 -= 1) {
    myservo1.write(pos1);              // tell servo to go to position in variable 'pos'

    // *servo head*
    pos2 = 0;
    myservo2.write(pos2);

    // *eyes*
    analogWrite(redleftpin, 255);
  analogWrite(greenleftpin, 0);
  analogWrite(blueleftpin, 0);
  analogWrite(redrightpin, 0);
  analogWrite(greenrightpin, 0);
  analogWrite(bluerightpin, 0);
    delay(10);
    analogWrite(redleftpin, 0);
  analogWrite(greenleftpin, 0);
  analogWrite(blueleftpin, 0);
  analogWrite(redrightpin, 0);
  analogWrite(greenrightpin, 255);
  analogWrite(bluerightpin, 0);
    delay(10);
    delay(10);
    }                     // waits 15ms for the servo to reach the position
  
  // *servo hand*
  for (pos1 = 0; pos1 <= 90; pos1 += 1) {
    myservo1.write(pos1); 

    // *servo head*
    pos2 = 90;
    myservo2.write(pos2);
   
    // *eyes*
    analogWrite(redleftpin, 255);
  analogWrite(greenleftpin, 0);
  analogWrite(blueleftpin, 0);
  analogWrite(redrightpin, 0);
  analogWrite(greenrightpin, 0);
  analogWrite(bluerightpin, 0);
    delay(10);
    analogWrite(redleftpin, 0);
  analogWrite(greenleftpin, 0);
  analogWrite(blueleftpin, 0);
  analogWrite(redrightpin, 0);
  analogWrite(greenrightpin, 255);
  analogWrite(bluerightpin, 0);
    delay(10);
    delay(10);
      }}

    // *distance sensor*
    // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  //Serial.print("Distance: ");
  Serial.println(distance);
  //Serial.println(" cm");
  
// *eye color*
//RGB_color(255, 0, 0); // Red
//  delay(1000);
//  RGB_color(0, 255, 0); // Green
//  delay(1000);
//  RGB_color(0, 0, 255); // Blue
//  delay(1000);
//  RGB_color(255, 255, 125); // Raspberry
//  delay(1000);
//  RGB_color(0, 255, 255); // Cyan
//  delay(1000);
//  RGB_color(255, 0, 255); // Magenta
//  delay(1000);
//  RGB_color(255, 255, 0); // Yellow
//  delay(1000);
//  RGB_color(255, 255, 255); // White
//  delay(1000);

  // *presssensor*
  presssensorValue = analogRead(presssensorPin);
  //Serial.println(presssensorValue);

   //*lightsensor*
  lightsensorValue = analogRead(lightsensorPin)*10;
  //Serial.println(lightsensorValue);
  }
  
  
