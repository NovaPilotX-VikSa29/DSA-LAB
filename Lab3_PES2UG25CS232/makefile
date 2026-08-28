# for task 1 change to client1.o/.c everywhere

test.exe : client_infi.o stack.o 
	gcc client_infi.o stack.o -o test.exe 
client_infi.o : client_infi.c stack.h
	gcc -Wall -c client_infi.c 
stack.o : stack.c stack.h 
	gcc -Wall -c stack.c 
	