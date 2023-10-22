#include <iostream>
#include <array>
#include <string>
#include <cstdlib>
#include "mainstructures.h"
#include "constants.h"

using namespace std;
using namespace cards_characteristics;
using namespace constants;

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

string getCardName(const Card& card) {
	string cardName = "";
	switch (card.suit) {
	case DIAMONDS: cardName += "D"; break;
	case HEARTS:   cardName += "H"; break;
	case CLUBS:    cardName += "C"; break;
	case SPADES:   cardName += "S"; break;
	default:	   cout << "\nCARD_SUIT_ERROR"; exit(CARD_SUIT_ERROR);
	}
	switch (card.rank) {
	case RANK_2:	 cardName += "2"; break;
	case RANK_3:	 cardName += "3"; break;
	case RANK_4:	 cardName += "4"; break;
	case RANK_5:	 cardName += "5"; break;
	case RANK_6:	 cardName += "6"; break;
	case RANK_7:	 cardName += "7"; break;
	case RANK_8:	 cardName += "8"; break;
	case RANK_9:	 cardName += "9"; break;
	case RANK_10:    cardName += "10"; break;
	case RANK_JACK:  cardName += "J"; break;
	case RANK_QUEEN: cardName += "Q"; break;
	case RANK_KING:	 cardName += "K"; break;
	case RANK_ACE:   cardName += "A"; break;
	default:		 cout << "\nCARD_RANK_ERROR"; exit(CARD_RANK_ERROR);
	}

	return cardName;
}

void print_card(const Card& card) {
	// вспомогательная функция вывода карт в формате "<масть><номинал>"
	cout << getCardName(card) << '\n';
}

void print_deck(const array<Card, deck_size>& deck) {
	for (int card = 0; card < deck_size; card++)
		print_card(deck.at(card));
}