#include <iostream>
#include <vector>
#include <string>
#include "mainstructures.h"
#include "patterns.h"

using namespace std;
using namespace cards_characteristics;
using namespace patterns;

void printCardTopPart(const Card& card, const int i) {
	switch (card.rank) {
		case RANK_UNKNOWN:  cout << cardsTopPart[13][i]; break;
		case RANK_2:		cout << cardsTopPart[12][i]; break;
		case RANK_3:		cout << cardsTopPart[11][i]; break;
		case RANK_4:		cout << cardsTopPart[10][i]; break;
		case RANK_5:		cout << cardsTopPart[9][i]; break;
		case RANK_6:		cout << cardsTopPart[8][i]; break;
		case RANK_7:		cout << cardsTopPart[7][i]; break;
		case RANK_8:		cout << cardsTopPart[6][i]; break;
		case RANK_9:		cout << cardsTopPart[5][i]; break;
		case RANK_10:		cout << cardsTopPart[4][i]; break;
		case RANK_JACK:		cout << cardsTopPart[3][i]; break;
		case RANK_QUEEN:	cout << cardsTopPart[2][i]; break;
		case RANK_KING:		cout << cardsTopPart[1][i]; break;
		case RANK_ACE:		cout << cardsTopPart[0][i]; break;
		default:			cout << "\nCARD_RANK_ERROR"; exit(CARD_RANK_ERROR);
	}
}

void printCardMiddlePart(const Card& card, const int i) {
	switch (card.suit) {
		case DIAMONDS:	       cout << cardsMiddlePart[0][i]; break;
		case HEARTS:	       cout << cardsMiddlePart[1][i]; break;
		case CLUBS:			   cout << cardsMiddlePart[2][i]; break;
		case SPADES:		   cout << cardsMiddlePart[3][i]; break;
		case SUIT_UNKNOWN:     cout << cardsMiddlePart[4][i]; break;
		default:			   cout << "\nCARD_SUIT_ERROR"; exit(CARD_SUIT_ERROR);
	}
}

void printCardBottomPart(const Card& card, const int i) {
	switch (card.rank) {
		case RANK_UNKNOWN:  cout << cardsBottomPart[13][i]; break;
		case RANK_2:	    cout << cardsBottomPart[12][i]; break;
		case RANK_3:		cout << cardsBottomPart[11][i]; break;
		case RANK_4:		cout << cardsBottomPart[10][i]; break;
		case RANK_5:		cout << cardsBottomPart[9][i]; break;
		case RANK_6:		cout << cardsBottomPart[8][i]; break;
		case RANK_7:		cout << cardsBottomPart[7][i]; break;
		case RANK_8:		cout << cardsBottomPart[6][i]; break;
		case RANK_9:		cout << cardsBottomPart[5][i]; break;
		case RANK_10:		cout << cardsBottomPart[4][i]; break;
		case RANK_JACK:		cout << cardsBottomPart[3][i]; break;
		case RANK_QUEEN:	cout << cardsBottomPart[2][i]; break;
		case RANK_KING:		cout << cardsBottomPart[1][i]; break;
		case RANK_ACE:		cout << cardsBottomPart[0][i]; break;
		default:            cout << "\nCARD_RANK_ERROR"; exit(CARD_RANK_ERROR);
	}
}

void output(vector <Card> playerCards, vector <Card> dealerCards) {
	system("cls");

	unsigned short playerCardsCount = playerCards.size();
	unsigned short dealerCardsCount = dealerCards.size();

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < playerCardsCount; j++) {
			printCardTopPart(playerCards.at(j), i);
		}
		cout << endl;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < playerCardsCount; j++) {
			printCardMiddlePart(playerCards.at(j), i);
		}
		cout << endl;
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < playerCardsCount; j++) {
			printCardBottomPart(playerCards.at(j), i);
		}
		cout << endl;
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < dealerCardsCount; j++) {
			printCardTopPart(dealerCards.at(j), i);
		}
		cout << endl;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < dealerCardsCount; j++) {
			printCardMiddlePart(dealerCards.at(j), i);
		}
		cout << endl;
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < dealerCardsCount; j++) {
			printCardBottomPart(dealerCards.at(j), i);
		}
		cout << endl;
	}
}