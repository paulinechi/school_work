
library : main.o syntax.o parse.o
	gcc -g -o library main.o syntax.o parse.o

main.o : main.c syntax.h parse.h
	gcc -c main.c

syntax.o : syntax.c parse.h
	gcc -c syntax.c
					
parse.o : parse.c
	gcc -c parse.c

clean:										
	rm -f library main.o syntax.o parse.o







