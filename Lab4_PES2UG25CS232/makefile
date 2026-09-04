# for 2nd task we need to change client name to client2

client2.exe : client2.o poly.o term.o 
	gcc client2.o poly.o term.o -o client2.exe
poly.o : poly.c poly.h 
	gcc -Wall -c poly.c
term.o : term.c term.h 
	gcc -Wall -c term.c 
client2.o : client2.c poly.h  term.h 
	gcc -Wall -c client2.c