#pragma once
#include "Card.h"
#include <vector>

namespace BlackjackRules {

	int getCardValue(const Card& card);

	int getHandScore(const std::vector<Card>& cards);
}