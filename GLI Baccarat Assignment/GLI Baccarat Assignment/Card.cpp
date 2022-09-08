#include <iostream>
#include <vector>
#include <string>
#include "Card.h"

/*
* Creates a new card. The value of the card is determined based on its name according to Baccarat rules.
*/
Card::Card(std::string name) {
	this->name = name;
	std::vector<std::string> picture_cards = { "J","Q","K" };
	if (std::find(picture_cards.begin(), picture_cards.end(), name) != picture_cards.end()) {
		this->value = 0;
	}
	else if (name == "A") {
		this->value = 1;
	}
	else {
		this->value = std::stoi(name);
	}
}

/*
* Getter method which returns the name of the card.
*/
std::string Card::get_name() {
	return name;
}

/*
* Getter method which returns the value of the card.
*/
int Card::get_value() {
	return value;
}