client.exe : client.o pqueue.o
	gcc client.o pqueue.o -o client.exe 
	
client.o : client.c pqueue.h 
	gcc -Wall -c client.c 

pqueue.o : pqueue.c pqueue.h 
	gcc -Wall -c pqueue.c 