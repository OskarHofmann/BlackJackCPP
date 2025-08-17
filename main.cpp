#include "Card.h"
#include "Deck.h"
#include <iostream>

int getBlackjackCardValue(const Card& card) {
	switch (card.rank) {
	case Card::rank_ace: return 11;
	case Card::rank_two: return 2;
	case Card::rank_three: return 3;
	case Card::rank_four: return 4;
	case Card::rank_five: return 5;
	case Card::rank_six: return 6;
	case Card::rank_seven: return 7;
	case Card::rank_eight: return 8;
	case Card::rank_nine: return 9;
	case Card::rank_ten: return 10;
	case Card::rank_jack: return 10;
	case Card::rank_queen: return 10;
	case Card::rank_king: return 10;
	default: return -1;
	}
}

int main()
{
	Deck deck{};
	std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

	deck.shuffle();
	std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

	return 0;
}