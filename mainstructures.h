#pragma once

namespace cards_characteristics {
	enum CardSuit {
		DIAMONDS,
		HEARTS,
		CLUBS,
		SPADES
	};

	enum CardRank {
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_10,
		RANK_JACK,
		RANK_QUEEN,
		RANK_KING,
		RANK_ACE
	};
}

struct Card {
	cards_characteristics::CardSuit suit;
	cards_characteristics::CardRank rank;
};