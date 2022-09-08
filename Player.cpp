#include <numeric>
#include "Player.h"
#include "Card.h"
#include "Shoe.h"

/*
* Initializes hand as an empty vector of Card objects.
*/
Player::Player() {
	this->hand = {};
}

/*
* Getter method that returns the vector of Card objects representing a players hand.
*/
std::vector<Card> Player::get_hand() {
	return hand;
}

/*
* Returns the value of the player's hand based on Baccarat rules.
*/
int Player::hand_value() {
	std::vector<int> card_values = {};
	for (Card card : hand) {
		card_values.push_back(card.get_value());
	}
	int hand_value = (std::accumulate(card_values.begin(), card_values.end(), 0)) % 10;
	return hand_value;
}

/*
* Represents a player drawing a card from the shoe. The card is drawn from the back of the shoe (see
* shoe.draw_card()) and then added to the players hand (as the last element). Returns the drawn card.
*/
Card Player::draw_card(Shoe& shoe) {
	Card drawn_card = shoe.draw_card();
	hand.push_back(drawn_card);
	return drawn_card;
}

