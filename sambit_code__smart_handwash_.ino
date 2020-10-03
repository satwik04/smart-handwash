#include <Servo.h>   
Servo servo;     
int trigPin = 5;    
int echoPin = 6;   
int servoPin = 7;
long duration, dist;    


void setup() {       
    Serial.begin(9600);
    servo.attach(7);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT); 
       servo.write(0);  
   
} 

void loop() {  
digitalWrite(trigPin, LOW);
delayMicroseconds(10);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
dist = (duration/4) / 29.1;    //to obtain distance as speed of sound is 343m/s that is (in cm/microseconds) equal to 1/29.1

 if ( dist<10 ) {
 Serial.println("the distance is less than 10");
 servo.write(90);  
 delay(1000);
 }     
else{
  servo.write(0);
}
     
Serial.print(dist);
}
