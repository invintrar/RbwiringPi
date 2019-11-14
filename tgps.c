#include <wiringSerial.h>
#include <stdio.h>

#define device "/dev/ttyAMA0" 

int main(){
	int fd;
	fd = serialOpen(device, 9600);
	if (fd > 0 ){
		printf("Iniciado Correctamente\n");
	}else{
		printf("NO se inicio puerto Serial");
	}
	
	serialClose(fd);

	return 0;
}
