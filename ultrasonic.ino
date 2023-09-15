#include <Servo.h>
Servo microServo;

#define TRIGGER 4
#define ECHO 3
#define SERVO 2

int distance = 0;
long duration = 0;
  
void setup() {
  // put your setup code here, to run once:
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  microServo.attach(SERVO, 544, 2400);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int index;
  
  for(index = 10; index <= 170; index++) {
  	microServo.write(index);
    delay(30);
    calculateDistance();
    
    Serial.print("Angulation: ");
    Serial.println(index);
    Serial.print("Distance: ");
    Serial.println(distance);
  }
  
  for(index = 170; index >= 10; index--) {
  	microServo.write(index);
    delay(20);
    calculateDistance();
    
    Serial.print("Angulation: ");
    Serial.print(index);
    Serial.print("Distance: ");
    Serial.print(distance);
  }
}
               
int calculateDistance() {
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration*0.017175;
  return distance;
}
