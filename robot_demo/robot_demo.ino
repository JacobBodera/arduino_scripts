// DEFINE PIN #'s
const int trigPin = 11;
const int echoPin = 10;
const int irPin = 12;
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

void setup() {
  // Button
  pinMode(buttonPin, INPUT);

  // Sonic 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // IR
  pinMode(irPin, INPUT);

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
  analogWrite(enA, 150);
	analogWrite(enB, 150);

  // Turn on motor A & B
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);

  bool ultraDetect = false;

  // Forward until ultrasonic is detected
  while(!ultraDetect){
//    Serial.println("Forward");

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

    if(distance <= 7){
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

  //Backwards

  // Turn on motor A & B
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);


  delay(1000);

    // stop on motor A & B
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
  delay(1000);
  // TUrn around
  // for(int i = 0; i<10; i++){
  //   Serial.println("Turning around");
  //   delay(100);
  // }

  //turning
  digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
  delay(950);// PLEASE ADJUST THIS NUMBER

  // stop on motor A & B
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
  delay(1000);

  // Turn on motor A & B
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);  

  bool IRdetect = false;

  while(!digitalRead(irPin)){
    
    delay(50);
  }

  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);

  while(true){
    Serial.println("Stop");
    delay(1000);
  }
}
