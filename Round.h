#pragma once
#include "Player.h"
#include "Deck.h"
#include <optional>

class Round
{
private: 
	Player m_player{};
	Player m_dealer{};
	std::optional<Deck> m_deck{}; // deck is optional to allow to draw random cards without a deck

	void printStart() const;
	void playerDraw();
	bool askPlayerForHit() const;
	void dealerDraw();
	void printEnd() const;

	Card drawCard();

public:
	Round() : Round{ std::nullopt } {}
	Round(std::optional<Deck> deck) : m_deck{ deck } {}
	
	void play();

};

