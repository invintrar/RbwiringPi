#include <stdio.h>
#include <wiringPi.h>

unsigned char bandera;

void interrupcion(void);

#define LED 7
#define IRQ 4

int main(){
	unsigned char i;
	bandera = 1;
	wiringPiSetup();
	pinMode(LED, OUTPUT);
	wiringPiISR(IRQ, INT_EDGE_FALLING, interrupcion);

	while(bandera){
		digitalWrite(LED, HIGH);
		delay(500);
		digitalWrite(LED, LOW);
		delay(500);
	}
}

void interrupcion(){
	printf("Continuar Ejecutando:0.-No 1.-Si\n");
	scanf("%d",&bandera);
}
