// DEFINE PIN #'s
const int trigPin = 11;
const int echoPin = 10;
const int buttonPin = 2;

// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5; 
int in4 = 4;

// DEFINE VARIABLES
long duration;
int distance;

int speed = 125;

void setup() {
  // Button
  pinMode(buttonPin, INPUT);

  // Sonic 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

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

  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // put your main code here, to run repeatedly:

  // Wait for starting condition
  while(!digitalRead(buttonPin)){}

  Serial.println("start");
  // Go forward
  analogWrite(enA, speed);
	analogWrite(enB, speed);

  // Turn on motor A & B
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);

  bool ultraDetect = false;

  // Forward until ultrasonic is detected
  while(!ultraDetect){
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
    distance = duration * 0.034 / 2;
    Serial.println(distance);
    if(distance <= 12){
      ultraDetect = true;
    }

    delay(50);
  }

  Serial.println("Ultra Detect");

  // stop on motor A & B
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
  delay(1000);

}
