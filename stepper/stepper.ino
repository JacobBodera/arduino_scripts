#include <AFMotor.h>

AF_DCMotor motor(3);
uint8_t speed = 200;

void setup() 
{
	//Set initial speed of the motor & stop
	motor.run(RELEASE);
}


void loop() {
  // motor.run(FORWARD);
  // motor.setSpeed(speed);
  // delay(4000);


}
