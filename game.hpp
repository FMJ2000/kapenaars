#ifndef GAME_HPP
#define GAME_HPP

#include <stack>
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "texture_manager.hpp"
#include "tile.hpp"

#define NAME "kapenaars"

class GameState;

class Game {
	private:
		void loadTextures();
		void loadTiles();

	public:
		const static int tileSize = 8;
		std::map<std::string, Tile> tileAtlas;
		std::stack<GameState *> states;
		sf::RenderWindow window;
		TextureManager texmgr;
		sf::Sprite background;
		
		void pushState(GameState * state);
		void popState();
		void changeState(GameState * state);
		GameState * peekState();
		void gameLoop();
		Game();
		~Game();
};

#endif