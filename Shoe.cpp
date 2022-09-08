#include <random>
#include "Shoe.h"
#include "Card.h"


/*
* Initializes the cards attribute as an empty vector of Card objects.
*/
Shoe::Shoe() {
	cards = {};
}

/*
* Called when a player draws a card from the shoe. Pops the last card in the shoe and returns it.
*/
Card Shoe::draw_card() {
	Card drawn_card = cards.back();
	cards.pop_back();
	return drawn_card;
}

/*
* Getter method which returns the vector containing cards in the shoe.
*/
std::vector<Card> Shoe::view_cards() {
	return cards;
}

/*
* Method for inserting cards into the shoe at the start of the game.
*/
void Shoe::insert_card(Card inserted_card) {
	cards.push_back(inserted_card);
}

/*
* Shuffles the shoe after all the cards have been inserted. The shuffling is done such that
* every possible permutation of Card objects is equally likely.
*/
void Shoe::shuffle() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::shuffle(cards.begin(), cards.end(), gen);
}
