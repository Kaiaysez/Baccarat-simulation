#pragma once
#include <iostream>

/*
* Represents a regular playing card. Does not contain suit information as it is not relevant to Bacarrat.
*/
class Card {

private:
	/*
	* A string representing the name of the card (eg. "A","5","K" etc).
	*/
	std::string name;

	/*
	* An integer representing the value of the card based on Baccarat rules (eg. J is worth 0 points, etc).
	*/
	int value;

public:
	/*
	* Creates a new card. The value of the card is determined based on its name according to Baccarat rules.
	*/
	Card(std::string name);

	/*
	* Getter method which returns the name of the card.
	*/
	std::string get_name();

	/*
	* Getter method which returns the value of the card.
	*/
	int get_value();
};
