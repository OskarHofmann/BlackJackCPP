#include "Round.h"
#include "Rules.h"
#include "Deck.h"
#include <iostream>

void Round::printStart() const
{
	std::cout << "The dealer is showing: ";
	m_dealer.printCards();
	std::cout << '(' << m_dealer.score() << ')' << '\n';

	std::cout << "You are showing: ";
	m_player.printCards();
	std::cout << '(' << m_player.score() << ')' << '\n';
}

void Round::playerDraw()
{
	while (askPlayerForHit()) {
		Card newCard{ drawCard() };
		std::cout << "You were dealt " << newCard << ". ";
		m_player.addCard(newCard);
		std::cout << "You now have " << m_player.score() << '\n';
		if (m_player.score() >= BlackjackRules::bustScore) {
			return;
		}
	}
}

bool Round::askPlayerForHit() const
{
	std::cout << "(h) to hit, or (s) to stand: ";
	char playerChoice;
	while (true) {
		std::cin >> playerChoice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any extra characters in the input buffer
		if (!(playerChoice == 'h' || playerChoice == 's')) {
			std::cout << "Invalid Input. Please try again.\n";
		}
		else {
			break;
		}
	}
	return (playerChoice == 'h');
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
	if (m_player.score() > BlackjackRules::bustScore) {
		std::cout << "You went bust!\nYou loose!";
		return;
	}
	if (m_dealer.score() > BlackjackRules::bustScore) {
		std::cout << "The dealer went bust!\n";
		std::cout << "You win!" << '\n';
		return;
	}
	if (m_dealer.score() > m_player.score()) {
		std::cout << "You loose!" << '\n';
		return;
	}
	if (m_dealer.score() == m_player.score()) {
		std::cout << "Tie" << '\n';
		return;
	}
	std::cout << "You win!" << '\n';
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
	playerDraw();
	if (m_player.score() < BlackjackRules::bustScore) {
		dealerDraw();
	}
	printEnd();
}
