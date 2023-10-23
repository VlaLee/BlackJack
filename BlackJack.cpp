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

void output(int cardsCount, vector <string> cardNum, vector <string> cardName) {
	system("cls");

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < cardsCount; j++) {
			string temp = cardNum[j];
			if (temp == "A") cout << cardsUp[0][i];
			if (temp == "K") cout << cardsUp[1][i];
			if (temp == "Q") cout << cardsUp[2][i];
			if (temp == "J") cout << cardsUp[3][i];
			if (temp == "10") cout << cardsUp[4][i];
			if (temp == "9") cout << cardsUp[5][i];
			if (temp == "8") cout << cardsUp[6][i];
			if (temp == "7") cout << cardsUp[7][i];
			if (temp == "6") cout << cardsUp[8][i];
			if (temp == "5") cout << cardsUp[9][i];
			if (temp == "4") cout << cardsUp[10][i];
			if (temp == "3") cout << cardsUp[11][i];
			if (temp == "2") cout << cardsUp[12][i];
		}
		cout << endl;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < cardsCount; j++) {
			string temp = cardName[j];
			if (temp == "clubs") cout << cardsMid[0][i];
			if (temp == "spades") cout << cardsMid[1][i];
			if (temp == "diamonds") cout << cardsMid[2][i];
			if (temp == "hearts") cout << cardsMid[3][i];
		}
		cout << endl;
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < cardsCount; j++) {
			string temp = cardNum[j];
			if (temp == "A") cout << cardsDown[0][i];
			if (temp == "K") cout << cardsDown[1][i];
			if (temp == "Q") cout << cardsDown[2][i];
			if (temp == "J") cout << cardsDown[3][i];
			if (temp == "10") cout << cardsDown[4][i];
			if (temp == "9") cout << cardsDown[5][i];
			if (temp == "8") cout << cardsDown[6][i];
			if (temp == "7") cout << cardsDown[7][i];
			if (temp == "6") cout << cardsDown[8][i];
			if (temp == "5") cout << cardsDown[9][i];
			if (temp == "4") cout << cardsDown[10][i];
			if (temp == "3") cout << cardsDown[11][i];
			if (temp == "2") cout << cardsDown[12][i];
		}
		cout << endl;
	}
}

gameResult playBlackJack(array<Card, deck_size>& deck, int bet){
	snuffleDeck(deck);
	int index = 0;
	int playerScore = 0;
	int dilerScore = 0;
	vector <string> playerCards;
	vector <string> dilerCards;
	vector <int> playerRankCards;
	vector <int> dilerRankCards;
 
	for (index; index < 3; index++){
		if (index % 2 == 0){
			playerScore += getCardValue(deck[index]);
			playerRankCards.push_back(deck[index].rank);
			playerCards.push_back(getCardName(deck[index]));
			// print card;
			
		}
		else {
			dilerScore += getCardValue(deck[index]);
			dilerRankCards.push_back(deck[index].rank);
			dilerCards.push_back(getCardName(deck[index]));
			// print card;
		}
	}
	cout << "p1 " << playerCards[0] << " ";
	cout << "p2 " << playerCards[1] << endl;
	cout << "d1 " << dilerCards[0] << endl;

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
			playerCards.push_back(getCardName(deck[index]));
			cout << getCardName(deck[index]) << " " << endl;
			index++;
			if (playerScore > 21){
				return LOSE;
			}
			//вывод карт
		}
		else {
			while (true){
				string nextCardVar = "0";
				cout << "Do You wanna take one more card. Enter ""Y"" or ""N"": ";
				cin >> nextCardVar;
				if (nextCardVar == "Y"){
					playerScore += getCardValue(deck[index]);
					playerCards.push_back(getCardName(deck[index]));
					cout << getCardName(deck[index]) << " ";
					index++;
					if (playerScore > 21){
						return LOSE;
					}
					//вывод карт
				} 
				if (nextCardVar == "N" || playerScore == 21){
					break;
				}
			}
		}
		dilerScore += getCardValue(deck[index]);
		dilerCards.push_back(getCardName(deck[index]));
		cout << getCardName(deck[index]) << " " ;
		index++;
		while (dilerScore < 17){
			dilerScore += getCardValue(deck[index]);
			dilerCards.push_back(getCardName(deck[index]));
			cout << getCardName(deck[index]) << " " ;
			index++;	
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
