spi:
	gcc -o output testspi.c -lwiringPi
	./output
	rm output
interrupcion:
	gcc -o output interrupcion.c -lwiringPi
	./output
	rm output
led:
	gcc -o output parpadeo.c -lwiringPi
	./output
	rm output
spiprueba:
	gcc -o output spiSpeed.c -lwiringPi
	./output
	rm output
pruebas:
	gcc -o output pruebas.c
	./output
	rm output
gps:
	gcc -o output ugps.c -lwiringPi
	./output
	rm output
uart:
	gcc -o output uart.c -lwiringPi
	./output
	rm output
