client : client.o date.o event.o eventlist.o
	gcc client.o date.o event.o eventlist.o -o client.exe
event.o : event.h event.c 
	gcc -Wall -c event.c
date.o : date.c date.h 
	gcc -Wall -c date.c 
eventlist.o : eventlist.c eventlist.h
	gcc -Wall -c eventlist.c
client.o : client.c date.h 
	gcc -Wall -c client.c