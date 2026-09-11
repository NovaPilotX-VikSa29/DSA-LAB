client.exe : client.o clist.o
	gcc client.o clist.o 
client.o : client.c clist.h 
	gcc -Wall -c client.c 
clist.o : clist.h clist.c 
	gcc -Wall -c clist.c
	