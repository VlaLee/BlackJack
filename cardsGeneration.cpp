#include <iostream>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include "mainstructures.h"
#include "constants.h"

using namespace std;
using namespace cards_characteristics;
using namespace constants;

void setRandomSettings() {
	srand(static_cast<unsigned int>(time(0)));
	rand();
}

int getRandomNumber(int min, int max) {
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void swapCard(Card& card_x, Card& card_y) {
	Card temp_card = card_x;
	card_x = card_y;
	card_y = temp_card;
}

void snuffleDeck(array<Card, deck_size>& deck) {
	for (int cardIndex = 0; cardIndex < deck_size; cardIndex++) {
		unsigned short swapIndex = getRandomNumber(0, 51);
		swapCard(deck.at(cardIndex), deck.at(swapIndex));
	}
}

unsigned short getCardValue(const Card& card) {
	switch (card.rank) {
	case RANK_2:	 return 2;
	case RANK_3:	 return 3;
	case RANK_4:	 return 4;
	case RANK_5:	 return 5;
	case RANK_6:	 return 6;
	case RANK_7:	 return 7;
	case RANK_8:	 return 8;
	case RANK_9:	 return 9;
	case RANK_10:    return 10;
	case RANK_JACK:  return 10;
	case RANK_QUEEN: return 10;
	case RANK_KING:	 return 10;
	case RANK_ACE:   return 11;
	default:         cout << "\nCARD_RANK_ERROR"; exit(CARD_RANK_ERROR);
	}
}

pair <string, string> getCardName(const Card& card) {
	pair <string, string> cardName = {"", ""};
	switch (card.suit) {
	case DIAMONDS: cardName.first += "D"; break;
	case HEARTS:   cardName.first += "H"; break;
	case CLUBS:    cardName.first += "C"; break;
	case SPADES:   cardName.first += "S"; break;
	default:	   cout << "\nCARD_SUIT_ERROR"; exit(CARD_SUIT_ERROR);
	}
	switch (card.rank) {
	case RANK_2:	 cardName.second += "2"; break;
	case RANK_3:	 cardName.second += "3"; break;
	case RANK_4:	 cardName.second += "4"; break;
	case RANK_5:	 cardName.second += "5"; break;
	case RANK_6:	 cardName.second += "6"; break;
	case RANK_7:	 cardName.second += "7"; break;
	case RANK_8:	 cardName.second += "8"; break;
	case RANK_9:	 cardName.second += "9"; break;
	case RANK_10:    cardName.second += "T"; break;
	case RANK_JACK:  cardName.second += "J"; break;
	case RANK_QUEEN: cardName.second += "Q"; break;
	case RANK_KING:	 cardName.second += "K"; break;
	case RANK_ACE:   cardName.second += "A"; break;
	default:		 cout << "\nCARD_RANK_ERROR"; exit(CARD_RANK_ERROR);
	}

	return cardName;
}

// void printCard(const Card& card) {
// 	// ��������������� ������� ������ ���� � ������� "<�����><�������>"
// 	cout << getCardName(card);
// }

// void printDeck(const array<Card, deck_size>& deck) {
// 	for (int cardIndex = 0; cardIndex < deck_size; cardIndex++)
// 		printCard(deck.at(cardIndex));
// }