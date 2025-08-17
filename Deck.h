#pragma once
#include "Card.h"
#include <array>

class Deck
{
private:
	static constexpr int numberOfCardsPerDeck{ 52 };
	std::array<Card, numberOfCardsPerDeck> m_cards {};
	std::size_t m_currentPosition{ 0 };

public:
	Deck();
	Card dealCard();
	void shuffle();
};

