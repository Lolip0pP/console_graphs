CC = gcc -Wall -Werror -Wextra

all : main.o parsing.o str.o calc.o graph.o
	$(CC) main.o parsing.o str.o calc.o graph.o -o ../build/graph

main.o : main.c
	$(CC) -c main.c -o main.o

calc.o : calc.c
	$(CC) -c calc.c -o calc.o

graph.o : graph.c 
	$(CC) -c graph.c -o graph.o

parsing.o : parsing.c 
	$(CC) -c parsing.c -o parsing.o

str.o : str.c 
	$(CC) -c str.c -o str.o

clean:
	rm -rf  *.o ../build/graph