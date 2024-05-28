// Motor A connections
#define enA 9
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
#define s3 10
#define rightSensor 6
#define leftSensor 2

#define button 14

int speed = 75;

int frequencyR = 0;
int frequencyL = 0;

int freqTolerance = 150;

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
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);

  pinMode(button, INPUT);
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

  Serial.begin(9600);
}

void loop(){
  Serial.println("Start");
  while(true)
  {
    Serial.println(digitalRead(button));
    delay(200);
  }
  Serial.println("button hit");
  // Read green value
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);

  // Go forward
  analogWrite(enA, speed);
	analogWrite(enB, speed);

  frequencyR = pulseIn(rightSensor, LOW);
  frequencyR = map(frequencyR, 300, 750, 0, 255);
  frequencyL = pulseIn(leftSensor, LOW);
  frequencyL = map(frequencyL, 300, 800, 0, 255);
//1+2 is left
//3+4 RIGHT
//lowhigh is back
//highlow is forwards
    // digitalWrite(in1, LOW);
	  // digitalWrite(in2, HIGH);
	  // digitalWrite(in3, HIGH);
	  // digitalWrite(in4, LOW);


  // Serial.print("Right = ");
  // Serial.println(frequencyR);
  // Serial.print("Left = ");
  // Serial.println(frequencyL);
  // Serial.println("");

  delay(200);
      digitalWrite(in1, LOW);
	  digitalWrite(in2, LOW);
	  digitalWrite(in3, LOW);
	  digitalWrite(in4, LOW);
}



