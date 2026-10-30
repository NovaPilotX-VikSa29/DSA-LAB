client.exe : client.o graph.o 
	gcc client.o graph.o -o client.exe 
client.o : client.c graph.h 
	gcc -Wall -c client.c 
graph.o : graph.c graph.h
	gcc -Wall -c graph.c 
	