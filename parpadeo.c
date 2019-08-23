#include <wiringPi.h>
#include <stdio.h>
#define LED 7

int main(){
	int i;
	wiringPiSetup();
	pinMode(LED, OUTPUT);
	for(i=0; i<10; i++){
		digitalWrite(LED,HIGH);
		delay(100);
		digitalWrite(LED,LOW);
		delay(100);
	}
	while(1){
		digitalWrite(LED, HIGH);
		delay(500);
		digitalWrite(LED,LOW);
		delay(500);
	}
	return 0;
}
