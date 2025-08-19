#include "Card.h"
#include "Rules.h"
#include <vector>

int BlackjackRules::getCardValue(const Card& card) {
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

int BlackjackRules::getHandScore(const std::vector<Card>& cards) {
	int score{ 0 };
	int aces{ 0 };
	for (const Card& card : cards) {
		score += getCardValue(card);
		if (card.rank == Card::rank_ace) {
			aces += 1;
		}
	}
	// if score > 21 and the hand contains aces, each ace can count as 1 insted
	while (score >= BlackjackRules::bustScore && aces > 1) {
		score -= 10;
		aces -= 1;
	}

	return score;
}

