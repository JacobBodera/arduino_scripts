
#include <Servo.h> 

// Motor A connections
#define enA 6
#define in1 8
#define in2 7
// Motor B connections
#define enB 3
#define in3 5
#define in4 4
// Color sensors
#define s0 13
#define s1 12
#define s2 11
#define s3 17
#define rightSensor 18
#define leftSensor 2

// #define echo 14
// #define trig 19
#define ir 19

#define button 15

Servo myservo;
int pos = 0;

int base = 200;
int change = 200;

int speed = 90;

int frequencyR = 0;
int frequencyL = 0;

int lineTolerance = 150;
int circleTolerance = 100;

int endDist = 5;
long duration;
int distance;

bool firsthalf = true;

void setup() 
{
  // color sensors
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(rightSensor, INPUT);
  pinMode(leftSensor, INPUT);
  // set frequency to 20%
  digitalWrite(s0, LOW);
  digitalWrite(s1, HIGH);

  // Motors
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);

  // button
  pinMode(button, INPUT);

  // pinMode(trig, OUTPUT);
  // pinMode(echo, INPUT);

  // Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);

  myservo.write(base);
  myservo.attach(16); 
  myservo.write(base);

  Serial.begin(9600);
}


void loop(){
  while(!digitalRead(button)) {}


  // First Half
  while(firsthalf){

    // Read green value
    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);

    // Go forward
    analogWrite(enA, speed);
    analogWrite(enB, speed);

    // frequencyR = pulseIn(rightSensor, LOW);
    // frequencyR = map(frequencyR, 100, 500, 0, 255);
    // frequencyL = pulseIn(leftSensor, LOW);
    // frequencyL = map(frequencyL, 100, 450, 0, 255);
    frequencyR = pulseIn(rightSensor, LOW);
    frequencyR = map(frequencyR, 100, 400, 0, 255);
    frequencyL = pulseIn(leftSensor, LOW);
    frequencyL = map(frequencyL, 100, 450, 0, 255);

    if (frequencyR < lineTolerance && frequencyL < lineTolerance) { // both detect 
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    else if (frequencyR > lineTolerance) { // only right detects
      digitalWrite(in1,  LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
    else if (frequencyL > lineTolerance) { // only left detects
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    else {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }

    Serial.print("Right = ");
    Serial.println(frequencyR);
    Serial.print("Left = ");
    Serial.println(frequencyL);
    Serial.println("");


    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
    
    frequencyR = pulseIn(rightSensor, LOW);
      // frequencyR = map(frequencyR, 50, 350, 0, 255);
    frequencyL = pulseIn(leftSensor, LOW);
      // frequencyL = map(frequencyL, 50, 350, 0, 255);

    if (frequencyR < circleTolerance && frequencyL < circleTolerance) 
    {
      firsthalf = false;
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);

      delay(500);
      close();
      delay(1000);
    }
    
  }

  //Second Half
  
  //Spin
  spin2();
  stop();
  delay(200);
  bool backwards = true;

  //line follow backwards
  while(backwards)
  {

    // Read green value
    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);

    // Go forward
    analogWrite(enA, speed);
    analogWrite(enB, speed);

    frequencyR = pulseIn(rightSensor, LOW);
    frequencyR = map(frequencyR, 100, 400, 0, 255);
    frequencyL = pulseIn(leftSensor, LOW);
    frequencyL = map(frequencyL, 100, 450, 0, 255);

    if (frequencyR < lineTolerance && frequencyL < lineTolerance) { // both detect 
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    else if (frequencyR > lineTolerance) { // only right detects
      digitalWrite(in1,  LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
    else if (frequencyL > lineTolerance) { // only left detects
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    else {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
    // checking ultrasonic distance
    //  digitalWrite(trig, LOW);
    //   delayMicroseconds(2);
    //   // Sets the trig on HIGH state for 10 micro seconds
    //   digitalWrite(trig, HIGH);
    //   delayMicroseconds(10);
    //   digitalWrite(trig, LOW);
    //   // Reads the echo, returns the sound wave travel time in microseconds
    //   duration = pulseIn(echo, HIGH);
    //   // Calculating the distance
    //   distance = duration * 0.034 / 2;

    //   if (distance < endDist && distance > 0) {
    //     digitalWrite(in1, LOW);
    //     digitalWrite(in2, LOW);
    //     digitalWrite(in3, LOW);
    //     digitalWrite(in4, LOW);
    //     delay(500);
    //     open();
    //     delay(500);
    //     while(true) {}
    //   }

    Serial.print("Right = ");
    Serial.println(frequencyR);
    Serial.print("Left = ");
    Serial.println(frequencyL);
    Serial.println("");

    if(!digitalRead(ir)){
      stop();
      delay(500);
      
      //backwards
      backwardss();
      delay(500);
      stop();
      open();
      delay(500);
      while(true) {}
    }
  }
  //Stop condition
  //Release

}

void close()
{
	// // sweeps from 0 degrees to 180 degrees
	for(pos = base; pos >= base-change; pos -= 1) 
	{
		myservo.write(pos);
		delay(5);
	}
  Serial.println("Extend");

}

void open()
{
	// sweeps from 180 degrees to 0 degrees
	for(pos = base-change ; pos<=base; pos+=1)
	{
		myservo.write(pos);
		delay(5);
	}
  delay(500);
  Serial.println("Retract");
}

void spin()
{
      analogWrite(enA, speed );
      analogWrite(enB, speed);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      delay(1170);
      analogWrite(enA, speed);
     analogWrite(enB, speed);
}

void spin2()
{

      analogWrite(enA, speed);
      analogWrite(enB, speed);
      int frequency = 0;
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      while (frequency < lineTolerance) {
        frequency = pulseIn(leftSensor, LOW);
        frequency = map(frequency, 100, 450, 0, 255);
      }
      delay(10);
     analogWrite(enA, speed);
     analogWrite(enB, speed);
}


void stop()
{
        digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
}
void backwardss()
{
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);

}
//1+2 is left
//3+4 RIGHT
//lowhigh is back
//highlow is forwards
