#include <SFML/Graphics.hpp>
#include <string>
#include "gui.hpp"

sf::Vector2f Gui::getSize() {
	return sf::Vector2f(this->dimensions.x, this->dimensions.y * this->entries.size());
}

int Gui::getEntry(const sf::Vector2f mousePos) {
	if (this->entries.size() == 0) return -1;
	if (!this->visible) return -1;
	for (int i = 0; i < this->entries.size(); i++) {
		sf::Vector2f point = mousePos;
		point += this->entries[i].shape.getOrigin();
		point -= this->entries[i].shape.getPosition();
		if (point.x < 0 || point.x > this->entries[i].shape.getScale().x * this->dimensions.x) continue;
		if (point.y < 0 || point.y > this->entries[i].shape.getScale().y * this->dimensions.y) continue;
		return i;
	}
	return -1;
}

void Gui::setEntryText(int entry, std::string text) {
	if (entry >= this->entries.size() || entry < 0) return;
	this->entries[entry].text.setString(text);
	return; 
}

void Gui::setDimensions(sf::Vector2f dimensions) {
	this->dimensions = dimensions;
	for (auto &entry: this->entries) {
		entry.shape.setSize(dimensions);
		entry.text.setCharacterSize(dimensions.y - this->style.borderSize - this->padding);
	}
	return;
}

void Gui::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	if (!this->visible) return;
	for (auto entry : this->entries) {
		target.draw(entry.shape);
		target.draw(entry.text);
	}
	return;
}

void Gui::show() {
	sf::Vector2f offset(0.0f, 0.0f);
	this->visible = true;
	for (auto &entry : this->entries) {
		sf::Vector2f origin = this->getOrigin();
		origin -= offset;
		entry.shape.setOrigin(origin);
		entry.text.setOrigin(origin);
		entry.shape.setPosition(this->getPosition());
		entry.text.setPosition(this->getPosition());
		if (this->horizontal) offset.x += this->dimensions.x;
		else offset.y += this->dimensions.y;
	}
	return;
}

void Gui::hide() {
	this->visible = false;
	return;
}

void Gui::highlight(const int entry) {
	for (int i = 0; i < this->entries.size(); ++i) {
		if (i == entry) {
			this->entries[i].shape.setFillColor(style.bodyHighlightCol);
			this->entries[i].shape.setOutlineColor(style.borderHighlightCol);
			this->entries[i].text.setFillColor(style.textHighlightCol);
			this->entries[i].text.setOutlineColor(style.textHighlightCol);
		} else {
			this->entries[i].shape.setFillColor(style.bodyCol);
			this->entries[i].shape.setOutlineColor(style.borderCol);
			this->entries[i].text.setFillColor(style.textCol);
			this->entries[i].text.setOutlineColor(style.textCol);
		}
	}
	return;
}

std::string Gui::activate(const int entry) {
	if (entry == -1) return "null";
	return this->entries[entry].message;
}

std::string Gui::activate(sf::Vector2f mousePos) {
	int entry = this->getEntry(mousePos);
	return this->activate(entry);
}