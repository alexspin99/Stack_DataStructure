# Project01 makefile

project01: stack.o main.o
	g++ stack.o main.o -o project01

stack.o: stack.h stack.cpp
	g++ -c stack.cpp

main.o: stack.h main.cpp
	g++ -c main.cpp

clean:
	rm *.o project01


