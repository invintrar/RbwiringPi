#include <wiringPiSPI.h>
#include <stdio.h>

#define CHANNEL 0

int main(){
	unsigned char data_env[30], i, bandera;

	if(wiringPiSPISetup(0,5000000)== -1){
		printf("Error\n");
		bandera=30;
	}else{
		printf("Inciados Correctament SPI0\n");
		bandera=0;
	}

	printf("%-14s  %-14s\n","Dato Enviado","Dato Recibido");


	for(i = 0; i < 30; i++){
		data_env[0] = bandera;
		data_env[1] = 0x00;
		wiringPiSPIDataRW(CHANNEL, data_env, sizeof(data_env));
		printf("%6.3X  %14.3X\n", bandera, data_env[1]);
		bandera++;
	}
}
