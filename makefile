all: main.o
	gcc -o statTest main.o

main.o: main.c
	gcc -c main.c

run:
		./statTest

clean:
	rm *.o
	rm *~
