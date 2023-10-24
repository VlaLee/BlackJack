#include <iostream>
#include <vector>
#include <string>
#include "mainstructures.h"
#include "patterns.h"

using namespace std;
using namespace cards_characteristics;
using namespace patterns;

void output(vector <Card> playerCards, vector <Card> dilerCards) {
	system("cls");

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < playerCards.size(); j++) {
			switch (playerCards.at(j).rank) {
			case RANK_2:	 cout << cardsUp[0] [i]; break;
			case RANK_3:	 cout << cardsUp[1] [i]; break;
			case RANK_4:	 cout << cardsUp[2] [i]; break;
			case RANK_5:	 cout << cardsUp[3] [i]; break;
			case RANK_6:	 cout << cardsUp[4] [i]; break;
			case RANK_7:	 cout << cardsUp[5] [i]; break;
			case RANK_8:	 cout << cardsUp[6] [i]; break;
			case RANK_9:	 cout << cardsUp[7] [i]; break;
			case RANK_10:    cout << cardsUp[8] [i]; break;
			case RANK_JACK:  cout << cardsUp[9] [i]; break;
			case RANK_QUEEN: cout << cardsUp[10][i]; break;
			case RANK_KING:	 cout << cardsUp[11][i]; break;
			case RANK_ACE:   cout << cardsUp[12][i]; break;
			default:                                 break;
			}
		}
		cout << endl;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < playerCards.size(); j++) {
			switch (playerCards.at(j).suit) {
			case DIAMONDS: cout << cardsMid[0][i]; break;
			case HEARTS:   cout << cardsMid[1][i]; break;
			case CLUBS:    cout << cardsMid[2][i]; break;
			case SPADES:   cout << cardsMid[3][i]; break;
			default:	                           break;
			}
		}
		cout << endl;
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < playerCards.size(); j++) {
			switch (playerCards.at(j).rank) {
			case RANK_2:	 cout << cardsDown[0] [i]; break;
			case RANK_3:	 cout << cardsDown[1] [i]; break;
			case RANK_4:	 cout << cardsDown[2] [i]; break;
			case RANK_5:	 cout << cardsDown[3] [i]; break;
			case RANK_6:	 cout << cardsDown[4] [i]; break;
			case RANK_7:	 cout << cardsDown[5] [i]; break;
			case RANK_8:	 cout << cardsDown[6] [i]; break;
			case RANK_9:	 cout << cardsDown[7] [i]; break;
			case RANK_10:    cout << cardsDown[8] [i]; break;
			case RANK_JACK:  cout << cardsDown[9] [i]; break;
			case RANK_QUEEN: cout << cardsDown[10][i]; break;
			case RANK_KING:	 cout << cardsDown[11][i]; break;
			case RANK_ACE:   cout << cardsDown[12][i]; break;
			default: 		                           break;
			}
		}
		cout << endl;
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < dilerCards.size(); j++) {
			switch (dilerCards.at(j).rank) {
			case RANK_2:	 cout << cardsUp[0] [i]; break;
			case RANK_3:	 cout << cardsUp[1] [i]; break;
			case RANK_4:	 cout << cardsUp[2] [i]; break;
			case RANK_5:	 cout << cardsUp[3] [i]; break;
			case RANK_6:	 cout << cardsUp[4] [i]; break;
			case RANK_7:	 cout << cardsUp[5] [i]; break;
			case RANK_8:	 cout << cardsUp[6] [i]; break;
			case RANK_9:	 cout << cardsUp[7] [i]; break;
			case RANK_10:    cout << cardsUp[8] [i]; break;
			case RANK_JACK:  cout << cardsUp[9] [i]; break;
			case RANK_QUEEN: cout << cardsUp[10][i]; break;
			case RANK_KING:	 cout << cardsUp[11][i]; break;
			case RANK_ACE:   cout << cardsUp[12][i]; break;
			default:                                 break;
			}
		}
		cout << endl;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < dilerCards.size(); j++) {
			switch (dilerCards.at(j).suit) {
			case DIAMONDS: cout << cardsMid[0][i]; break;
			case HEARTS:   cout << cardsMid[1][i]; break;
			case CLUBS:    cout << cardsMid[2][i]; break;
			case SPADES:   cout << cardsMid[3][i]; break;
			default:	                           break;
			}
		}
		cout << endl;
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < dilerCards.size(); j++) {
			switch (dilerCards.at(j).rank) {
			case RANK_2:	 cout << cardsDown[0] [i]; break;
			case RANK_3:	 cout << cardsDown[1] [i]; break;
			case RANK_4:	 cout << cardsDown[2] [i]; break;
			case RANK_5:	 cout << cardsDown[3] [i]; break;
			case RANK_6:	 cout << cardsDown[4] [i]; break;
			case RANK_7:	 cout << cardsDown[5] [i]; break;
			case RANK_8:	 cout << cardsDown[6] [i]; break;
			case RANK_9:	 cout << cardsDown[7] [i]; break;
			case RANK_10:    cout << cardsDown[8] [i]; break;
			case RANK_JACK:  cout << cardsDown[9] [i]; break;
			case RANK_QUEEN: cout << cardsDown[10][i]; break;
			case RANK_KING:	 cout << cardsDown[11][i]; break;
			case RANK_ACE:   cout << cardsDown[12][i]; break;
			default: 		                           break;
			}
		}
		cout << endl;
	}
}