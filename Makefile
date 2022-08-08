all: main

main: main.o
	g++ main.o -o sfml-screensave -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o sfml-screensave
