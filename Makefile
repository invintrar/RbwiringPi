spi:
	gcc -o output testspi.c -lwiringPi
	./output
	rm output
interrupcion:
	gcc -o output interrupcion.c -lwiringPi
parpadeo:
	gcc -o output parpadeo.c -lwiringPi
	./output
	rm output
spiprueba:
	gcc -o output spiSpeed.c -lwiringPi
pruebas:
	gcc -o output pruebas.c
