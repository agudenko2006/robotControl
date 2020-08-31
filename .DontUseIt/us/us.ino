const int trig = 3;
const int echo = 2;
void setup() {
	pinMode(trig, OUTPUT);
	pinMode(13, OUTPUT);
	pinMode(4, OUTPUT);
	Serial.begin(9600);
	digitalWrite(4,1);
	digitalWrite(13,1);
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
	while(1==1){
		delay(5000);
		if(distance()<8){
			digitalWrite(13,1);
			delay(5000);
			return 0;
		}
	}
}


void loop() {
	if(distance()<8){
		stop();
	}else{
		Serial.print("Distance: ");
		Serial.println(distance());
	}
}