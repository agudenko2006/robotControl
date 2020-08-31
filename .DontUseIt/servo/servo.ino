#include <Servo.h>

Servo s1;

void setup() {
	s1.attach(9);
}
void loop() {
	while(1==1){
		s1.write(180);
		delay(1000);
		s1.write(0);
		delay(1000);
	}
}