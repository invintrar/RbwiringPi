#include <stdio.h>
#include <stdint.h>

typedef struct _data_received{
	uint32_t op1;
	uint32_t op2;
}data_received;
data_received received;

int main(){
	unsigned char i;
	unsigned char data[] = {'P','i','n','g','R','X'};
	uint8_t recv_data[32];
	uint8_t time;

	for(i = 0; i < 32; i++){
		recv_data[i] = 0x20;
	}

	received = *((data_received *) &recv_data);

	for(i = 0; i < 32; i++){
		printf("%2X",(received.op1>>(i*8)));
	}
	printf("\n");

	for(i = 0; i < 32; i++){
		printf("%2X",(received.op2>>(i*8)));
	}
	printf("\n");

	printf("Recivido:");
	for(i = 0; i<sizeof(data); i++){
		printf("%c",data[i]);
	}
	printf("\n");

	time = 0x01;
	printf("%2X", time);
	time =0x01;
	printf("%2X\n", time);

}
