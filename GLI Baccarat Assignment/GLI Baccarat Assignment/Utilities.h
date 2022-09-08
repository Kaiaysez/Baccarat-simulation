#pragma once
#include <iostream>;

class Player; //forward declaration


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
bool tableau(int banker_total, int players_third_card);


/*
* Evaluates the result of the game once both player(punco) and banker(banco) have already checked
* if they are required to draw a third card. "PLAYER" is returned if the player(punco) hand value is
* greater than the banker(banco) hand value and vice versa. "TIE" is returned if both players have
* the same hand value.
*/
std::string evaluate_result(Player player, Player banker);

/*
* Prints the cards in the player's (either punco or banco) hand in the required format.
*/
void print_player_hand(Player player);


/*
* Prints the final result in the required format.
*/
void print_result(Player player, Player banker);