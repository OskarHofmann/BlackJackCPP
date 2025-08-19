#pragma once
#include "Card.h"
#include "Deck.h"
#include "Rules.h"
#include <vector>


class Player {
private:

	std::vector<Card> m_cards{};

public:

	Player() = default;

	int score() const { return BlackjackRules::getHandScore(m_cards); }
	
	void drawCard();
	void drawCard(Deck& deck);

};