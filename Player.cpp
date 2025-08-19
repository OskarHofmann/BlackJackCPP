#include "Player.h"
#include "Deck.h"
#include <iostream>

void Player::addCard(Card card) {
	m_cards.push_back(card);
}

void Player::printCards() const
{
	for (const Card& card : m_cards) {
		std::cout << card << ' ';
	}
}
