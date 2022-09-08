
#include <iostream>
#include <random>
#include <string>
#include <numeric>
#include <map>
#include "Card.h"
#include "Shoe.h"
#include "Player.h"
#include "Utilities.h"

// NOTES/ASSUMPTIONS:
// 
// 1. Based on the rules of the game and what I have seen from the sample output, suit is unimportant, and so
//    I have not included the suit of cards, only the name (A,1,2,...,J,Q,K)
// 
// 2. I opted to go for an object oriented programming approach as it was mentioned during the interview.
// 
// 3. Since this is a simulation with no user input and only built in libraries are allowed, I assumed that
//    exception handling and unit testing is not within the scope of the assignment. However, I would be 
//    happy to implement it if you would like me to!
// 
// 4. Instead, I tested the correctness of the program by running the simulation 10000 times and verifying
//    that the results match the theoretical probabilities which I found online (Banker 45.8%, Player 44.6%,
//    and Tie 9.6%). The simulation code is in the Simulation.cpp file. To use it, simply comment the code
//    in the main.cpp and uncomment the code in Simulation.cpp.
// 
// 5. I have added in some code to main() that prints out the shoe and player hands before and after cards
//    are drawn to make it easier to verify that the program runs as intended. Instead of deleting the
//    code I simply commented it out for the convenience of the person going through this program.   
// 

int main() {


	// Instantiate the shoe such that it is a combined deck of 8 standard decks of 52 playing cards,
	// resulting in the shoe having a total of 416 cards. The suit does not matter in Baccarat, so the shoe
	// has 32 cards of each type (i.e 32 Aces, 32 Kings,...).
	Shoe shoe = Shoe();
	std::vector<std::string> card_types = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	for (std::string card_type : card_types) {
		for (int i = 0; i < 32; i++) {
			shoe.insert_card(Card(card_type));
		}
	}
	// Shuffle the shoe such that every permutation of cards is equally likely.
	shoe.shuffle();

	/*
	// Print contents of shoe.
	for (Card card : shoe.view_cards()) {
		std::cout << card.get_name() << " ";
	}
	*/

	// Instantiate player(punco) and banker(banco).
	Player player = Player();
	Player banker = Player();

	// Both player and banker draw 2 cards from the shoe.
	player.draw_card(shoe);
	banker.draw_card(shoe);
	player.draw_card(shoe);
	banker.draw_card(shoe);

	// Determine if a third card should be drawn.
	if (player.hand_value() <= 7 and banker.hand_value() <= 7) {
		if (player.hand_value() <= 5) {
			Card player_third_card = player.draw_card(shoe);
			if (tableau(banker.hand_value(), player_third_card.get_value()) == true) {
				banker.draw_card(shoe);
			}
		}
		else {
			if (banker.hand_value() <= 5) {
				banker.draw_card(shoe);
			}
		}
	}

	// Print the result in the required format.
	print_result(player, banker);

	/*
	// Print banker hand.
	std::cout << '\n';
	std::cout << "Banker Hand:" << '\n';
	print_player_hand(banker);

	// Print player hand.
	std::cout << '\n';
	std::cout << "Player Hand:" << '\n';
	print_player_hand(player);

	// Print banker and player hand value.
	std::cout << '\n';
	std::cout << "Banker hand value: " << banker.hand_value() << '\n';
	std::cout << "Player hand value: " << player.hand_value() << '\n';

	// Print contents of shoe.
	for (Card card : shoe.view_cards()) {
		std::cout << card.get_name() << " ";
	}
	*/

	return 0;


}
