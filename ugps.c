/**
*
*Author: darwinzh
*
*/
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <wiringPi.h>
#include <wiringSerial.h>
#include <time.h>
#include <stdlib.h>

#define device "/dev/ttyS0"

int main(){
	time_t seconds;
	int serial_port;
	char data;
	/* Open serial port */
	if((serial_port = serialOpen(device, 9600)) < 0){
		fprintf(stderr, "Unable to open serial device: %s\n", strerror(errno));
		return 1;
	}
	/* Initializes wiringPi setup */
	if (wiringPiSetup() == -1){
		fprintf(stdout, "Unable to start wiringPi: %s\n", strerror(errno));
		return 1;
	}

	while(1){
		/* comprobamos datos esten disponibles */
		if(serialDataAvail(serial_port)){
			/* receive character serially */
			data = serialGetchar(serial_port);
			printf("%c ", data);
			fflush(stdout);
			/* transmit character serially on port */
			//serialPutchar(serial_port, data);
		}
	}
}
