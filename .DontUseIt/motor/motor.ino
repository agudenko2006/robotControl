#define mA1 3
#define mA2 5
#define mB1 10
#define mB2 11
void setup() {
	pinMode(mA1, OUTPUT);
	pinMode(mA2, OUTPUT);
	pinMode(mB1, OUTPUT);
	pinMode(mB2, OUTPUT);
	pinMode(13, OUTPUT);
	digitalWrite(13,1);
	Serial.begin(9600);
	analogWrite(mA1,255);
	analogWrite(mA2,255);
}


void drive(int a,int b){
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
void stop(){
	drive(50,50);
	digitalWrite(13,0);
	while(1==1){
		delay(5000);
	}
}


void loop() {
	for(int i=0;i<100;i++){
		drive(i,i);
		delay(100);
	}
	for(int i=100;i>0;i){
		drive(i,i);
		delay(100);
	}
	stop();
}