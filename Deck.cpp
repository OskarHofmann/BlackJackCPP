#include "Deck.h"
#include "Random.h"
#include <cassert>
#include <algorithm>


Deck::Deck()
{
	// make sure that number of suits and ranks fit to the number of cards per deck
	static_assert(std::ssize(Card::allRanks) * std::ssize(Card::allSuits) == numberOfCardsPerDeck);
	
	std::size_t cardPosition{ 0 };
	for (Card::Suit suit : Card::allSuits) {
		for (Card::Rank rank : Card::allRanks) {
			m_cards[cardPosition] = Card(rank, suit);
			++cardPosition;
		}
	}
}

Card Deck::dealCard()
{
	assert(m_currentPosition < numberOfCardsPerDeck && "Deck::dealCard() ran out of cards.");
	return m_cards[m_currentPosition++];
}

void Deck::shuffle()
{
	std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
}
