graph : main.o graph.o queue.o
	gcc -o graph main.o graph.o queue.o

main.o : main.c
	gcc -c main.c

graph.o : graph.c graph.h
	gcc -c graph.c

queue.o : queue.c queue.h
	gcc -c queue.c