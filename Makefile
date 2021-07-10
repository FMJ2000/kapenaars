CC = g++
CFLAGS = -Wall -g 
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

main: main.o game.o game_state_start.o game_state_editor.o texture_manager.o
	$(CC) $(CFLAGS) -o main main.o game.o $(SFMLFLAGS)

main.o: main.cpp game.hpp game_state_start.hpp
	$(CC) $(CFLAGS) -c main.cpp 

game.o: game.hpp game_state.hpp

game_state_start.o: game_state_start.hpp game_state_editor.hpp game_state.hpp

game_state_editor.o: game_state.hpp game_state_editor.hpp

texture_manager.o: texture_manager.hpp