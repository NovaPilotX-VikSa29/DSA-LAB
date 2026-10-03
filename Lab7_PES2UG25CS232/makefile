main.exe : main.o dequeue.o
	gcc main.o dequeue.o -o main.exe
	
main.o : main.c dequeue.h
	gcc -Wall -c main.c

dequeue.o : dequeue.c dequeue.h
	gcc -Wall -c dequeue.c