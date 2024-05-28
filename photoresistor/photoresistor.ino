int leftPhoto = 3;
int rightPhoto = 2;


void setup() {
  // put your setup code here, to run once:
  pinMode(leftPhoto, INPUT);
  pinMode(rightPhoto, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("");
  Serial.println(analogRead(rightPhoto));
  Serial.println(analogRead(leftPhoto));
  Serial.println("");

  delay(1000);
}
