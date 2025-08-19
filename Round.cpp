#include "Round.h"
#include "Rules.h"
#include "Deck.h"
#include <iostream>

void Round::printStart() const
{
	std::cout << "The dealer is showing: " << m_dealer.score() << '\n';
	std::cout << "You have: " << m_player.score() << '\n';
}

void Round::dealerDraw()
{
	while (m_dealer.score() < BlackjackRules::dealerDrawLimit) {
		Card newCard{ drawCard() };
		m_dealer.addCard(newCard);
		std::cout << "The dealer flips a " << newCard << ". They now have: " << m_dealer.score() << '\n';
	}
}

void Round::printEnd() const
{
	if (m_dealer.score() > BlackjackRules::bustScore) {
		std::cout << "You win!" <<'\n';
		return;
	}
	if (m_dealer.score() > m_player.score()) {
		std::cout << "You loose!" << '\n';
		return;
	}
	std::cout << "Tie!" << '\n';
}


Card Round::drawCard() {
	if (m_deck) {
		return m_deck.value().dealCard();
	}
	return Deck::dealRandomCard();
}

void Round::play()
{
	m_dealer.addCard(drawCard());
	m_player.addCard(drawCard());
	m_player.addCard(drawCard());

	printStart();
	dealerDraw();
	printEnd();
}
