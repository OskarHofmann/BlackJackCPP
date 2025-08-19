#pragma once
#include "Player.h"
#include <optional>

class Round
{
private: 
	Player m_player{};
	Player m_dealer{};
	std::optional<Deck> m_deck{};

	void printStart() const;
	void dealerDraw();
	void printEnd() const;

	Card drawCard();

public:
	Round() : Round{ std::nullopt } {}
	Round(std::optional<Deck> deck) : m_deck{ deck } {}
	
	void play();

};

