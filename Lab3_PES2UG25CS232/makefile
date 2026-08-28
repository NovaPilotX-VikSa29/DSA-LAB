client.exe : client1.o stack.o
	gcc client1.o stack.o -o client.exe 
client1.o : client1.c stack.h 
	gcc -Wall -c client1.c 
stack.o : stack.c stack.h 
	gcc -Wall -c stack.c 
	