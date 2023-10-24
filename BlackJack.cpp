#include <iostream>
#include <array>
#include <string>
#include <vector>
#include "cardsgeneration.h"
#include "constants.h"
#include "mainstructures.h"
#include "patterns.h"

using namespace patterns;
using namespace std;
using namespace cards_characteristics;
using namespace constants;

int bet = 0;
int bank = 1000;

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

gameResult playBlackJack(array<Card, deck_size>& deck, int bet){
	snuffleDeck(deck);
	int index = 0;
	int playerScore = 0;
	int dilerScore = 0;
	vector <Card> playerCards;
	vector <Card> dilerCards;
	vector <int> playerRankCards;
	vector <int> dilerRankCards;
 
	for (index; index < 3; index++){
		if (index % 2 == 0){
			playerScore += getCardValue(deck[index]);
			playerRankCards.push_back(deck[index].rank);
			playerCards.push_back(deck[index]);

			output(playerCards,dilerCards);
		}
		else {
			dilerScore += getCardValue(deck[index]);
			dilerRankCards.push_back(deck[index].rank);
			dilerCards.push_back(deck[index]);

			output(playerCards,dilerCards);
			
		}
	}
	// cout << "p1 " << playerCards[0] << " ";
	// cout << "p2 " << playerCards[1] << endl;
	// cout << "d1 " << dilerCards[0] << endl;

	// output(playerCards,dilerCards); (не нужно)

	// if (playerRankCards[0] == playerRankCards[1] || (playerRankCards[0] >= 9 && playerRankCards[1] >= 9)){
	// 	string splitVar = "0";
	// 	cout << "Do You wanna split? If You do it double your bet and enter ""Yes"" ";
	// 	cin >> splitVar;
	// 	if (splitVar == "Yes"){
	// 		vector <vector <string>> playerCardsSplit;
	// 		int pla
	// 		playerCardsSplit1.push_back(playerCards[0]);
	// 		playerCardsSplit2.push_back(playerCards[1]);
	// 		int playerScoreSplit1 = getCardValue(deck[0]);
	// 		int playerScoreSplit2 = getCardValue(deck[2]);
	// 		playerCardsSplit1.push_back(getCardName(deck[index]));
	// 		playerScoreSplit1 += getCardValue(deck[index]);
	// 	}
	// }
	if (playerRankCards[0] == 12 && playerRankCards[1] == 12)
	return WIN;

	if (playerScore < 21){
		string betVar = "0";
		cout << "Do you wanna double bet? Enter ""Y"": ";
		cin >> betVar;
		if (betVar == "Y"){
			bet *= 2;
			playerScore += getCardValue(deck[index]);
			playerCards.push_back(deck[index]);
			index++;

			output(playerCards,dilerCards);

			if (playerScore > 21){
				return LOSE;
			}
			
			
		}
		else {
			while (true){
				string nextCardVar = "0";
				cout << "Do You wanna take one more card. Enter ""Y"" or ""N"": ";
				cin >> nextCardVar;
				if (nextCardVar == "Y"){
					playerScore += getCardValue(deck[index]);
					playerCards.push_back(deck[index]);
					index++;

					output(playerCards,dilerCards);
					if (playerScore > 21){
						return LOSE;
					}
					
				} 
				if (nextCardVar == "N" || playerScore == 21){
					break;
				}
			}
		}
		dilerScore += getCardValue(deck[index]);
		dilerCards.push_back(deck[index]);
		index++;

		output(playerCards,dilerCards);

		while (dilerScore < 17){
			dilerScore += getCardValue(deck[index]);
			dilerCards.push_back(deck[index]);
			index++;
			
			output(playerCards,dilerCards);
		}
		
		if (dilerScore > 21 || playerScore > dilerScore){
			return WIN;
		}
		else if (dilerScore == playerScore){
			return DRAW;
		}
		else{
			return LOSE;
		}
	}
	
	


	// cout << playerRankCards[0] << " " << playerRankCards[1] << endl;
	// cout << dilerRankCards[0] << endl;
	output(playerCards,dilerCards);
	
	return WIN;
}


int main() {
	setRandomSettings();
    array<Card, deck_size> gameDeck;
    unsigned short iterC = 0;
    for (int suit = 0; suit < max_suit; suit++) {
        for (int rank = 0; rank < max_rank; rank++) {
            gameDeck.at(iterC).suit = static_cast<CardSuit>(suit);
            gameDeck.at(iterC).rank = static_cast<CardRank>(rank);
            iterC++;
        }
    }
	string startVar = "0";
	cout << "To start the game enter ""Y"": ";
	cin >> startVar;
	if (startVar == "Y"){
		//int startBank = 1000;
		//cout << "You start with 1000" << endl;
		while (true){
			// int bet = 0;
			//cout << "Place a bet. The minimum amount is 20" << endl;
			//cin >> bet;
			//bank -= bet;
			cout << endl;
			cout << playBlackJack(gameDeck, bet) << endl;
			cout << "Y / N " << endl;
			cin >> startVar;
			if (startVar == "N") break;
		}
	}
	// Card x;
	// x.suit = DIAMONDS;
	// x.rank = RANK_JACK;
	// vector <Card> playerCard;
	// playerCard.push_back(x);
	// x.suit = CLUBS;
	// x.rank = RANK_ACE;
	// playerCard.push_back(x);

	// Card y;
	// y.suit = HEARTS;
	// y.rank = RANK_QUEEN;
	// vector <Card> dilerCard;
	// dilerCard.push_back(y);

	// output(playerCard,dilerCard);
}