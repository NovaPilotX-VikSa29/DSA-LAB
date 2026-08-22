a.exe : rect.o mylist.o client.o
	gcc rect.o mylist.o client.o
mylist.o : mylist.c mylist.h
	gcc -Wall -c mylist.c
rect.o : rect.c rect.h
	gcc -Wall -c rect.c
client.o : client.c rect.h mylist.h
	gcc -Wall -c client.c