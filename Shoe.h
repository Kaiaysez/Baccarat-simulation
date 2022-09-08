#pragma once
#include <iostream>
#include <vector>
#include "Card.h"


/*
* Represents the shoe in Baccarat. It is empty when first initialized.
*/
class Shoe {

private:
	/*
	* A vector of Card objects representing the shoe.
	*/
	std::vector<Card> cards;

public:
	/*
	* Initializes the cards attribute as an empty vector of Card objects.
	*/
	Shoe();

	/*
	* Called when a player draws a card from the shoe. Pops the last card in the shoe and returns it.
	*/
	Card draw_card();

	/*
	* Getter method which returns the vector containing cards in the shoe.
	*/
	std::vector<Card> view_cards();

	/*
	* Method for inserting cards into the shoe at the start of the game.
	*/
	void insert_card(Card inserted_card);

	/*
	* Shuffles the shoe after all the cards have been inserted. The shuffling is done such that
	* every possible permutation of Card objects is equally likely.
	*/
	void shuffle();
};