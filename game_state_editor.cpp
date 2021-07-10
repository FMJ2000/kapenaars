#include <SFML/Graphics.hpp>
#include "game_state.hpp"
#include "game_state_editor.hpp"

void GameStateEditor::draw(const float dt) {
	this->game->window.clear(sf::Color::Black);
	this->game->window.draw(this->game->background);
	return;
}

void GameStateEditor::update(const float dt) {
	return;
}

void GameStateEditor::handleInput() {
	sf::Event event;
	while (this->game->window.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				this->game->window.close();
				break;

			case sf::Event::Resized:
				this->gameView.setSize(event.size.width, event.size.height);
				this->guiView.setSize(event.size.width, event.size.height);
				this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0), this->guiView));
				this->game->background.setScale(float(event.size.width) / float(this->game->background.getTexture()->getSize().x), float(event.size.height) / float(this->game->background.getTexture()->getSize().y));
				break;
		}
	}
}

GameStateEditor::GameStateEditor(Game * game) {
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->guiView.setSize(pos);
	this->gameView.setSize(pos);
	pos *= 0.5f;
	this->guiView.setCenter(pos);
	this->gameView.setCenter(pos);
}