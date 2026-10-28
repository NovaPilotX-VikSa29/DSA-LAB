client.exe : client.o tree.o queue.o
	gcc client.o tree.o queue.o -o client.exe
client.o : client.c tree.h
	gcc -Wall -c client.c
tree.o : tree.c tree.h
	gcc -Wall -c tree.c
queue.o : queue.c queue.h
	gcc -Wall -c queue.c