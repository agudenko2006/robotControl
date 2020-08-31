void setup(){
	Serial.begin(9600);
	Serial.setTimeout(50);
	pinMode(13,OUTPUT);
	digitalWrite(13,0);
	pinMode(3,OUTPUT);
	pinMode(6,OUTPUT);
	pinMode(5,OUTPUT);
}
void loop(){
	int red=0;
	if (Serial.available() > 1){
		char key = Serial.read();
		int val = Serial.parseInt();
		switch(key){
			case 'a' : analogWrite(3,val); break;
			case 'b' : analogWrite(6,val); break;
			case 'l' : analogWrite(5,val); break;
			default: digitalWrite(3,0); digitalWrite(6,0); digitalWrite(5,0); break;
		}
	}
}
