// DEFINE PIN #'s
// const int trigPin = 11;
// const int echoPin = 10;
// const int cen_irPin = 12;
// const int left_irPin = 13;
// const int right_irPin = 2;
const int buttonPin = 2;

// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

int speed = 100;

void setup() {

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
  // while(!digitalRead(buttonPin)){}
  delay(500);

  Serial.println("start");
  // Go forward
  analogWrite(enA, speed);
	analogWrite(enB, speed);

  // Turn on motor A & B
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
  delay(1500);

  // stop on motor A & B
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
  delay(1000);

  digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
  delay(600);

    // stop on motor A & B
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
  delay(1000);


  while(true){
    Serial.println("Stop");
    delay(1000);
  }
}
