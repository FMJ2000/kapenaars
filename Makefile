CC = g++
CFLAGS = -Wall -g 
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS = main.o texture_manager.o game.o game_state_start.o game_state_editor.o animation_handler.o tile.o map.o gui.o city.o

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o main $(OBJECTS) $(SFMLFLAGS)

main.o: main.cpp game.hpp game_state_start.hpp
	$(CC) $(CFLAGS) -c main.cpp 

texture_manager.o: texture_manager.hpp

game.o: game.hpp game_state.hpp texture_manager.hpp tile.hpp animation_handler.hpp gui.hpp

game_state_start.o: game_state_start.hpp game_state_editor.hpp game_state.hpp gui.hpp

game_state_editor.o: game_state.hpp game_state_editor.hpp map.hpp gui.hpp city.hpp

animation_handler.o: animation_handler.hpp

tile.o: animation_handler.hpp tile.hpp

map.o: map.hpp tile.hpp

gui.o: gui.hpp

city.o: city.hpp map.hpp tile.hpp