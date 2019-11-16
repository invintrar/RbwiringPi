#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <wiringPi.h>
#include <wiringSerial.h>
#include <time.h>
#include <stdlib.h>

#define device "/dev/ttyAMA0"

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

	//serialPrintf(serial_port, "PMTK314,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0");
	//serialPrintf(serial_port, "PMTK220,1000");

	while(1){

		if(serialDataAvail(serial_port)){
			/* receive character serially */
			data = serialGetchar(serial_port);
			printf("%c ", data);
			fflush(stdout);
			/* transmit character serially on port */
			serialPutchar(serial_port, data);
		}
		//time(&seconds);
		//printf("Seconds since January 1, 1970 = %ld\n", seconds);
		//delay(1000);
	}
}
