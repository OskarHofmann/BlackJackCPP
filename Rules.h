#pragma once
#include "Card.h"
#include <vector>

namespace BlackjackRules {

	constexpr int bustScore{ 22 };
	constexpr int dealerDrawLimit{ 17 };

	int getCardValue(const Card& card);

	int getHandScore(const std::vector<Card>& cards);

}