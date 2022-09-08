#include <iostream>
#include <map>
#include "Utilities.h"
#include "Player.h"
#include "Card.h"

/*
* The tableau to be consulted if the player(punco) draws a third card.
*
* Parameters:
*     banker_total(int): Value of bankers hand
*     players_third_card(int): Value of players third card
*
* Return:
*     true(bool) or false(bool) based on the key formed by the parameters.
*
* The map contains key-value pairs representing the following:
*
*	Key: An integer pair where the first element is the banker(banco)'s hand value, and the
*        second element is the value of the player(punco)'s third card.
*	Value: True means that the banker should draw a third card. False means that the banker stands.
*/
bool tableau(int banker_total, int players_third_card) {
	std::map<std::pair<int, int>, bool> tableau_map = {
		{{0,0},true},{{0,1},true},{{0,2},true},{{0,3},true},{{0,4},true},{{0,5},true},{{0,6},true},
		{{0,7},true},{{0,8},true},{{0,9},true},
		{{1,0},true},{{1,1},true},{{1,2},true},{{1,3},true},{{1,4},true},{{1,5},true},{{1,6},true},
		{{1,7},true},{{1,8},true},{{1,9},true},
		{{2,0},true},{{2,1},true},{{2,2},true},{{2,3},true},{{2,4},true},{{2,5},true},{{2,6},true},
		{{2,7},true},{{2,8},true},{{2,9},true},
		{{3,0},true},{{3,1},true},{{3,2},true},{{3,3},true},{{3,4},true},{{3,5},true},{{3,6},true},
		{{3,7},true},{{3,8},false},{{3,9},true},
		{{4,0},false},{{4,1},false},{{4,2},true},{{4,3},true},{{4,4},true},{{4,5},true},{{4,6},true},
		{{4,7},true},{{4,8},false},{{4,9},false},
		{{5,0},false},{{5,1},false},{{5,2},false},{{5,3},false},{{5,4},true},{{5,5},true},{{5,6},true},
		{{5,7},true},{{5,8},false},{{5,9},false},
		{{6,0},false},{{6,1},false},{{6,2},false},{{6,3},false},{{6,4},false},{{6,5},false},{{6,6},true},
		{{6,7},true},{{6,8},false},{{6,9},false},
		{{7,0},false},{{7,1},false},{{7,2},false},{{7,3},false},{{7,4},false},{{7,5},false},{{7,6},false},
		{{7,7},false},{{7,8},false},{{7,9},false},

	};
	return tableau_map[{banker_total, players_third_card}];
};


/*
* Evaluates the result of the game once both player(punco) and banker(banco) have already checked
* if they are required to draw a third card. "PLAYER" is returned if the player(punco) hand value is
* greater than the banker(banco) hand value and vice versa. "TIE" is returned if both players have
* the same hand value.
*/
std::string evaluate_result(Player player, Player banker) {
	if (player.hand_value() > banker.hand_value()) {
		return "PLAYER";
	}
	else if (player.hand_value() < banker.hand_value()) {
		return "BANKER";
	}
	else if (player.hand_value() == banker.hand_value()) {
		return "TIE";
	}
};

/*
* Prints the cards in the player's (either punco or banco) hand in the required format.
*/
void print_player_hand(Player player) {
	for (int i = 0; i < player.get_hand().size(); i++) {
		if (i != 0) {
			std::cout << ",";
		}
		std::cout << player.get_hand()[i].get_name();
	}
	std::cout << "  ";
};


/*
* Prints the final result in the required format.
*/
void print_result(Player player, Player banker) {
	std::cout << '\n';
	std::cout << "PHand BHand Outcome" << '\n';
	print_player_hand(player);
	print_player_hand(banker);
	std::cout << evaluate_result(player, banker);
};