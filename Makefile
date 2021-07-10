CC = g++
CFLAGS = -Wall -g 
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

main: main.o game.o
	$(CC) $(CFLAGS) -o main main.o game.o $(SFMLFLAGS)

main.o: main.cpp game.hpp
	$(CC) $(CFLAGS) -c main.cpp 

game.o: game.hpp game_state.hpp