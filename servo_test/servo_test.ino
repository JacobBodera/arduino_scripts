#include <Servo.h> 

Servo myservo;	// create servo object to control a servo
int pos = 0;	// variable to store the servo position
const int buttonPin = 2;
int base = 200;
int change = 200;

// Motor A connections
int enA = 15;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

int speed = 150;

void setup() 
{
	// attaches the servo on pin 10 to the servo object
  // while(!digitalRead(buttonPin)){}
  // Serial.println("Button");

  // Motors
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);

  // Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);

  // Servo
  myservo.write(base);
  myservo.attach(14); 
  myservo.write(base);
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);

}

void loop() 
{ 
  analogWrite(enA, speed-20);
	analogWrite(enB, speed+70);
  while(!digitalRead(buttonPin)) {}

  close();
  delay(2000);
  forward();
  delay(1000);

  stop();

  delay(500);

  backward();

  delay(1000);

  stop();

  delay(500);

  spin1();
  delay(1500);
  spin2();
  delay(1500);
  stop();
  delay(500);
  open();
  delay(500);
  backward();
  delay(500);

  stop();


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
  

void forward()
{
// Go forward
// Go forward


  // Turn on motor A & B
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);

}

void stop()
{
  // stop on motor A & B
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

void spin1()
{

  // Turn on motor A & B
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);

}

void spin2()
{

  // Turn on motor A & B
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);

}

void backward()
{
  analogWrite(enA, 150);
	analogWrite(enB, 150);
    // Turn on motor A & B
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
}