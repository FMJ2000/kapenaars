#ifndef CITY_HPP
#define CITY_HPP

#include <vector>
#include <map>
#include "map.hpp"

class City {
	private:
		float currentTime;
		float timePerDay;
		std::vector<int> shuffledTiles;
		double populationPool;
		double employmentPool;
		float propCanWork;
		double birthRate;
		double deathRate;
		double distributePool(double &pool, Tile &tile, double rate);
	
	public:
		Map map;
		double population;
		double employable;
		double residentialTax;
		double commercialTax;
		double industrialTax;
		double earnings;
		double funds;
		int day;
		
		City() {
			this->birthRate = 0.00055;
			this->deathRate = 0.00023;
			this->propCanWork = 0.50;
			this->populationPool = 0;
			this->population = this->populationPool;
			this->employmentPool = 0;
			this->employable = employmentPool;
			this->residentialTax = 0.05;
			this->commercialTax = 0.05;
			this->industrialTax = 0.05;
			this->earnings = 0;
			this->funds = 0;
			this->currentTime = 0.0;
			this->timePerDay = 1.0;
			this->day = 0;
		}
		City(std::string cityName, int tileSize, std::map<std::string, Tile> &tileAtlas): City() {
			this->map.tileSize = tileSize;
			load(cityName, tileAtlas);
		}
		void load(std::string cityName, std::map<std::string, Tile> &tileAtlas);
		void save(std::string cityName);
		void update(float dt);
		void bulldoze(const Tile &tile);
		void shuffleTiles();
		void tileChanged();
		double getHomeless() { return this->populationPool; }
		double getUnemployed() { return this->employmentPool; }
};

#endif