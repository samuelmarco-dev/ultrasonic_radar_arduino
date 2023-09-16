#include <Servo.h>
Servo microServo;

#define TRIGGER 8
#define ECHO 9
#define SERVO 11
#define BUZZER 3

int distance = 0;
long duration = 0;
int freq = 200;
  
void setup() {
  // put your setup code here, to run once:
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  microServo.attach(SERVO);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int index;
  
  for(index = 10; index <= 170; index++) {
  	microServo.write(index);
    delay(30);
    calculateDistance();
    
    Serial.print(index);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
  
  for(index = 170; index >= 10; index--) {
  	microServo.write(index);
    delay(20);
    calculateDistance();
    
    Serial.print(index);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
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
  actBuzzer(distance);

  return distance;
}

void actBuzzer(int dist) {
  if(dist <= 20) {
    tone(BUZZER, freq);
  } else{
    noTone(BUZZER);
  }
}
