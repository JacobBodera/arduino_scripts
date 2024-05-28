#define s0 13
#define s1 12
#define s2 11
#define s3 17
#define rightSensor 18
#define leftSensor 2

int frequencyR = 0;
int frequencyL = 0;

void setup() 
{
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(rightSensor, INPUT);
  pinMode(leftSensor, INPUT);

  digitalWrite(s0, LOW);
  digitalWrite(s1, HIGH);

  Serial.begin(9600);
}

void loop(){
  // Read red value
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);

  frequencyR = pulseIn(rightSensor, LOW);
    frequencyR = map(frequencyR, 100, 400, 0, 255);
    frequencyL = pulseIn(leftSensor, LOW);
    frequencyL = map(frequencyL, 100, 450, 0, 255);


  Serial.print("Right = ");
  Serial.println(frequencyR);
  Serial.print("Left = ");
  Serial.println(frequencyL);
  Serial.println("");
  delay(500);
  
}


