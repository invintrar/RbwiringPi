#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>

int main(){
	int fd;
	int count;
	int nextCh;
	unsigned int nextTime;

	if((fd = serialOpen("/dev/ttyAMA0",9600)) < 0){
		fprintf(stderr, "Unable to open serial device: %s\n",strerror(errno));
		return 1;
	}
	if(wiringPiSetup() == 1){
		fprintf(stdout, "Unable to start wiringPi: %s\n", strerror(errno));
		return 1;
	}

	nextTime = millis() + 300;

	for(count = 0; count < 3;count++){
		printf("\nOut: %3d: ", count);
		if(millis() > nextTime){
			printf("Out: %3d: ", count);
			fflush(stdout);
			char in_recieved;//What the  Pi recieves fro the module
		}
		/* Begin Here */
		while(serialDataAvail(fd)){
			nextCh = serialGetchar(fd);
			printf(" -> %3d", nextCh);
			if (nextCh == -1)
				break;
			fflush(stdout);
		}// end while
	}// end for
	serialClose(fd);
	return 0;
}
