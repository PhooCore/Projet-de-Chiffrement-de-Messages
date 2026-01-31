all: main

main: main.o source.o
	gcc -o main main.o source.o

main.o: main.c source.h
	gcc -c main.c

source.o: source.c source.h
	gcc -c source.c

clean:
	rm -f main.o source.o main
