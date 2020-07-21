#include <Servo.h>
#define trig 4
#define echo 2
#define mA1 3
#define mA2 5
#define mB1 10
#define mB2 11
#define sP1 9
#define sP2 8
#define sP3 7
#define sP4 12
#define sP6 6
Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo sa2;
Servo sa3;
Servo sa4;
Servo sa5;
Servo sa6;
Servo sa7;
Servo sd6;
void setup(){
	Serial.begin(9600);
	Serial.setTimeout(50);
	pinMode(mA1, OUTPUT);
	pinMode(mA2, OUTPUT);
	pinMode(mB1, OUTPUT);
	pinMode(mB2, OUTPUT);
	pinMode(trig, OUTPUT);
	pinMode(13, OUTPUT);
	pinMode(A0, OUTPUT);
	pinMode(A1, OUTPUT);
	pinMode(A7, OUTPUT);
	pinMode(sP1, OUTPUT);
	pinMode(sP2, OUTPUT);
	pinMode(sP3, OUTPUT);
	pinMode(sP4,OUTPUT);
	sa2.attach(A2);
	sa3.attach(A3);
	sa4.attach(A4);
	sa5.attach(A5);
	sa6.attach(A6);
	pinMode(sP6, OUTPUT);
	digitalWrite(13,1);
}

void driveA(int a){
	if(a==50){
		digitalWrite(mA1,0);
		digitalWrite(mA2,0);
	}else if(a>50){
		a = map(a, 50, 100, 0, 255);
		analogWrite(mA1,a);
		analogWrite(mA2,0);
	}else if(a<50){
		a = map(a, 0, 50, 255, 0);
		analogWrite(mA1,0);
		analogWrite(mA2,a);
	}	
}
void driveB(int b){
	if(b==50){
		digitalWrite(mB1,0);
		digitalWrite(mB2,0);
	}else if(b>50){
		b = map(b, 50, 100, 0, 255);
		analogWrite(mB1,b);
		analogWrite(mB2,0);
	}else if(b<50){
		b = map(b, 0, 50, 255, 0);
		analogWrite(mB1,0);
		analogWrite(mB2,b);
	}
}
int distance(){
	long duration;
	int distance;
	digitalWrite(trig,0);
	delayMicroseconds(2);
	digitalWrite(trig, 1);
	delayMicroseconds(10);
	digitalWrite(trig, 0);
	duration = pulseIn(echo, 1);
	distance= duration*0.034/2;
	return distance;
}
int stop(){
	digitalWrite(13,0);
	digitalWrite(A0,0);
	digitalWrite(A1,0);
	driveA(50);
	driveB(50);
	while(1==1){
		delay(5000);
		if(distance()<8){
			digitalWrite(13,1);
			digitalWrite(A0,1);
			digitalWrite(A1,1);
			delay(5000);
			digitalWrite(13,0);
			digitalWrite(A0,0);
			digitalWrite(A1,0);
			return 0;
		}
	}
}


void loop(){
	if (Serial.available() > 1){
		char key = Serial.read();
		int val = Serial.parseInt();
		switch(key){
			case 'a':
				driveA(val);
				break;
			case 'b':
				driveB(val);
				break;
			case 'l':
				digitalWrite(13,val);
				break;
			case 'c'://s1
				s1.attach(9);
				s1.write(val);
				break;
			case 'z'://s1 as pin
				analogWrite(sP1,val);
				break;
			case 'd'://s2
				s2.attach(8);
				s2.write(val);
				break;
			case 'x'://s2 as pin
				digitalWrite(sP2,val);
				break;
			case 'f'://s3
				s3.attach(7);
				s3.write(val);
				break;
			case 'o'://s3 as pin
				digitalWrite(sP3,val);
				break;
			case 'g'://s4
				s4.attach(12);
				s4.write(val);
				break;
			case 'p'://s4 as pin
				digitalWrite(sP4,val);
				break;
			case 'h'://side servo
				sd6.attach(6);
				sd6.write(val);
				break;
			case 'u'://side servo as pin
				digitalWrite(sP6,val);
				break;
			case 'i':
				digitalWrite(A0,val);
				break;
			case 'j':
				digitalWrite(A1,val);
				break;
			case 'k':
				digitalWrite(A7,val);
				break;
			case 'n':
				sa7.attach(A0);
				sa7.write(val);
				break;
			case 'm':
				sa7.attach(A1);
				sa7.write(val);
				break;
/*------------qwerty-is-analog-pins------------*/// 
			case 'q':
				sa2.write(val);
				break;
			case 'w':
				sa3.write(val);
				break;
			case 'e':
				sa4.write(val);
				break;
			case 'r':
				sa5.write(val);
				break;
			case 't':
				sa6.write(val);
				break;
			case 'y':
				sa7.attach(A7);
				sa7.write(val);
				break;
			case 'v':
				stop();
				break;
			default:
				driveA(50);
				driveB(50);
				digitalWrite(13,0);
				break;
		}
	}else{
		if(distance()<8){
			stop();
		}else{
			Serial.println(distance());
		}
	}
}
