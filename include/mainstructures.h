#pragma once

namespace cards_characteristics {
	enum CardSuit {
		DIAMONDS,
		HEARTS,
		CLUBS,
		SPADES,
		SUIT_UNKNOWN
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
		RANK_ACE,
		RANK_UNKNOWN
	};
}

enum gameResult {
	WIN,
	LOSE,
	DRAW,
	CONTINUE // special gameResult value
};

enum exitCode {
	NO_ERRORS,
	CARD_SUIT_ERROR,
	CARD_RANK_ERROR
};

struct Card {
	cards_characteristics::CardSuit suit;
	cards_characteristics::CardRank rank;
};