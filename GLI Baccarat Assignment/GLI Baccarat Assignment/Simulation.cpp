
//#include <iostream>
//#include <random>
//#include <string>
//#include <numeric>
//#include <map>
//#include "Card.h"
//#include "Shoe.h"
//#include "Player.h"
//#include "Utilities.h"
//
///*
//* Runs 1 simulation game of Baccarat. Returns "PLAYER" if the player wins, "BANKER" if the banker wins, 
//* and "TIE" if it's a tie.
//*/
//std::string simulation() {
//
//	// Instantiate the shoe such that it is a combined deck of 8 standard decks of 52 playing cards,
//	// resulting in the shoe having a total of 416 cards. The suit does not matter in Baccarat, so the shoe
//	// has 32 cards of each type (i.e 32 Aces, 32 Kings,...).
//	Shoe shoe = Shoe();
//	std::vector<std::string> card_types = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
//	for (std::string card_type : card_types) {
//		for (int i = 0; i < 32; i++) {
//			shoe.insert_card(Card(card_type));
//		}
//	}
//	// Shuffle the shoe such that every permutation of cards is equally likely.
//	shoe.shuffle();
//
//	// Instantiate player(punco) and banker(banco).
//	Player player = Player();
//	Player banker = Player();
//
//	// Both player and banker draw 2 cards from the shoe.
//	player.draw_card(shoe);
//	banker.draw_card(shoe);
//	player.draw_card(shoe);
//	banker.draw_card(shoe);
//
//	// Determine if a third card should be drawn.
//	if (player.hand_value() <= 7 and banker.hand_value() <= 7) {
//		if (player.hand_value() <= 5) {
//			Card player_third_card = player.draw_card(shoe);
//			if (tableau(banker.hand_value(), player_third_card.get_value()) == true) {
//				banker.draw_card(shoe);
//			}
//		}
//		else {
//			if (banker.hand_value() <= 5) {
//				banker.draw_card(shoe);
//			}
//		}
//	}
//
//	// Determines the result and returns "PLAYER","BANKER" or "TIE".
//	return evaluate_result(player, banker);
//}
//
///*
//* Runs simulation() 10000 times and records the number of player wins, banker wins and ties. Prints the
//* results. Might take up to a minute to run.
//* The theoretical probabilities according to online sources are banker 45.8% win chance, 
//* player 44.6% win chance, and tie 9.6%.
//*/ 
//int main() {
//
//	int player_win = 0;
//	int banker_win = 0;
//	int tie = 0;
//
//	// Adjust the number of simulations if it is taking too long to run.
//	for (int i = 1; i <= 10000; i++) {
//		std::string result = simulation();
//		if (result == "PLAYER") {
//			player_win += 1;
//		}
//		else if (result == "BANKER") {
//			banker_win += 1;
//		}
//		else if (result == "TIE") {
//			tie += 1;
//		}
//	}
//	std::cout << "Player wins " << player_win << " times" << '\n';
//	std::cout << "Banker wins " << banker_win << " times" << '\n';
//	std::cout << "Tie happens " << tie << " times";
//
//	return 0;
//}
