/**
*
*Author: darwinzh
*
*/
#include <wiringPiSPI.h>
#include <stdio.h>

#define CHANNEL 0

int main(){
	unsigned char data_env[30], i, j, bandera;

	if(wiringPiSPISetup(CHANNEL,5000000)== -1){
		printf("Error\n");
		bandera=30;
	}else{
		printf("Inciados Correctament SPI0\n");
		bandera=0;
	}

	printf("%-14s  %-14s\n","Dato Enviado","Dato Recibido");


	for(j = 0; j <= 0x1D; j++){
		if(bandera == 0x0A || bandera == 0x0B || bandera == 0x10){
			data_env[0] = bandera;
			//Llenamos la matriz para enviar 
			for(i = 1; i < 6; i++){
				data_env[i] = 0x00;
			}
		}else{
			data_env[0] = bandera;
			data_env[1] = 0x00;
		}

		wiringPiSPIDataRW(CHANNEL, data_env, sizeof(data_env));

		if(bandera == 0x0A || bandera == 0x0B || bandera == 0x10){
			printf("%6.2X  ",bandera);
			printf("%10.2X%.2X%.2X%.2X%.2X\n", data_env[1], data_env[2], data_env[3], data_env[4], data_env[5]);
		}else{
			printf("%6.2X  %18.10X\n", bandera, data_env[1]);
		}
		bandera++;
	}
}
