ET : main.o stack.o postfix.o expressiontree.o etstack.o
	gcc -o et main.o stack.o postfix.o expressiontree.o etstack.o

main.o : main.c
	gcc -c main.c

stack.o : stack.c stack.h
	gcc -c stack.c

postfix.o : postfix.c postfix.h
	gcc -c postfix.c

expressiontree.o : expressiontree.c expressiontree.h
	gcc -c expressiontree.c

etstack.o : etstack.c etstack.h
	gcc -c etstack.c