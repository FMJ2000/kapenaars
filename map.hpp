#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <vector>
#include "tile.hpp"

class Map {
	private:
		void depthfirstsearch(std::vector<TileType> &whitelist, sf::Vector2i pos, int label, int type);

	public:
		unsigned int width;
		unsigned int height;
		std::vector<Tile> tiles;
		std::vector<int> resources;
		unsigned int tileSize;
		unsigned int numRegions[1];
		std::vector<char> selected;
		unsigned int numSelected;

		void select(sf::Vector2i start, sf::Vector2i end, std::vector<TileType> blacklist);
		void clearSelected();
		void load(const std::string &filename, unsigned int width, unsigned int height, std::map<std::string, Tile> &tileAtlas);
		void save(const std::string &filename);
		void draw(sf::RenderWindow &window, float dt);
		void findConnectedRegions(std::vector<TileType> whitelist, int type);
		void updateDirection(TileType tileType);
		Map() {
			this->numSelected = 0;
			this->tileSize = 8;
			this->width = 0;
			this->height = 0;
			this->numRegions[0] = 1;
		}
		Map(const std::string &filename, unsigned int width, unsigned int height, std::map<std::string, Tile> &tileAtlas) {
			this->numSelected = 0;
			this->tileSize =8;
			load(filename, width, height, tileAtlas);
		}
};

#endif