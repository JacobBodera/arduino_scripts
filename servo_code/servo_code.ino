#include <Servo.h> 

Servo myservo;	// create servo object to control a servo
int pos = 0;	// variable to store the servo position
const int buttonPin = 14;
int base = 200;
int change = 200;
void setup() 
{
	// attaches the servo on pin 10 to the servo object
  // while(!digitalRead(buttonPin)){}
  // Serial.println("Button");


  myservo.write(base);
  myservo.attach(15); 
  myservo.write(base);
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);

}

void loop() 
{


  while(!digitalRead(buttonPin)) {}
  delay(200);
  close();

  while(!digitalRead(buttonPin))
  delay(200);

  open();
  
}


void close()
{
	// // sweeps from 0 degrees to 180 degrees
  // while(!digitalRead(buttonPin)) {}
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
  