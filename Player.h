#pragma once
#include <iostream>
#include <vector>
#include "Shoe.h"

/*
* Represents the players in the game, namely the player(punto) and the banker(banco).
*/
class Player {

private:
	/*
	* A vector of Card objects representing a player's hand.
	*/
	std::vector<Card> hand;

public:
	/*
	* Initializes hand as an empty vector of Card objects.
	*/
	Player();

	/*
	* Getter method that returns the vector of Card objects representing a players hand.
	*/
	std::vector<Card> get_hand();

	/*
	* Returns the value of the player's hand based on Baccarat rules.
	*/
	int hand_value();

	/*
	* Represents a player drawing a card from the shoe. The card is drawn from the back of the shoe (see
	* shoe.draw_card()) and then added to the players hand (as the last element). Returns the drawn card.
	*/
	Card draw_card(Shoe& shoe);
};