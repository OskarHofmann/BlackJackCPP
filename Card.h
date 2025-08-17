#pragma once
#include <ostream>
#include <array>

struct Card {
	enum Rank {
		rank_ace,
		rank_two,
		rank_three,
		rank_four,
		rank_five,
		rank_six,
		rank_seven,
		rank_eight,
		rank_nine,
		rank_ten,
		rank_jack,
		rank_queen,
		rank_king,

		numberOfRanks
	};

	enum Suit {
		suit_clubs,
		suit_diamonds,
		suit_hearts,
		suit_spades,

		numberOfSuits
	};

	Rank rank{};
	Suit suit{};

	static constexpr std::array allRanks{ rank_ace, rank_two, rank_three, rank_four, rank_five, rank_six, rank_seven, rank_eight, rank_nine, rank_ten, rank_jack, rank_queen, rank_king };
	static constexpr std::array allSuits{ suit_clubs, suit_diamonds, suit_hearts, suit_spades };

	friend std::ostream& operator<<(std::ostream& out, const Card& card);
};