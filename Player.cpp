#include "Player.h"
#include "Deck.h"

// when no deck is provided, draw random card
void Player::drawCard() {
	m_cards.push_back(Deck::dealRandomCard());
}

void Player::drawCard(Deck& deck) {
	m_cards.push_back(deck.dealCard());
}