#pragma once
#include "Card.h"
#include "Rules.h"
#include <vector>


class Player {
private:

	std::vector<Card> m_cards{};

public:

	Player() = default;

	int score() const { return BlackjackRules::getHandScore(m_cards); }

	void addCard(Card card);

	void printCards() const;

};