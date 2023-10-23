#include <iostream>
#include <vector>
#include <string>
#include "patterns.h"


using namespace patterns;
using namespace std;

void output(int cardsCount, vector <string> cardNum, vector <string> cardName) {
	system("cls");

	for (int i = 0; i < 6; i ++){
        for (int j = 0; j < cardsCount; j ++){
            string temp = cardNum[j];
            if (temp == "A") cout << cardsUp [0][i];
            if (temp == "K") cout << cardsUp [1][i];
            if (temp == "Q") cout << cardsUp [2][i];
            if (temp == "J") cout << cardsUp [3][i];
            if (temp == "10") cout << cardsUp [4][i];
            if (temp == "9") cout << cardsUp [5][i];
            if (temp == "8") cout << cardsUp [6][i];
            if (temp == "7") cout << cardsUp [7][i];
            if (temp == "6") cout << cardsUp [8][i];
            if (temp == "5") cout << cardsUp [9][i];
            if (temp == "4") cout << cardsUp [10][i];
            if (temp == "3") cout << cardsUp [11][i];
            if (temp == "2") cout << cardsUp [12][i];
        }
        cout << endl;
    }

    for (int i = 0; i < 8; i ++){
        for (int j = 0; j < cardsCount; j ++){
            string temp = cardName[j];
            if (temp == "clubs") cout << cardsMid[0][i];
            if (temp == "spades") cout << cardsMid[1][i];
            if (temp == "diamonds") cout << cardsMid[2][i];
            if (temp == "hearts") cout << cardsMid[3][i];
        }
        cout << endl;
    }
    
    for (int i = 0; i < 6; i ++){
        for (int j = 0; j < cardsCount; j ++){
            string temp = cardNum[j];
            if (temp == "A") cout << cardsDown [0][i];
            if (temp == "K") cout << cardsDown [1][i];
            if (temp == "Q") cout << cardsDown [2][i];
            if (temp == "J") cout << cardsDown [3][i];
            if (temp == "10") cout << cardsDown [4][i];
            if (temp == "9") cout << cardsDown [5][i];
            if (temp == "8") cout << cardsDown [6][i];
            if (temp == "7") cout << cardsDown [7][i];
            if (temp == "6") cout << cardsDown [8][i];
            if (temp == "5") cout << cardsDown [9][i];
            if (temp == "4") cout << cardsDown [10][i];
            if (temp == "3") cout << cardsDown [11][i];
            if (temp == "2") cout << cardsDown [12][i];
        }
        cout << endl;
    }
}

int main() {
	const int cardsCount = 4;
	vector <string> cardName = {"A", "3", "6", "10"};
	vector <string> cardNum = {"clubs", "hearts", "spades", "diamonds"};  //Трефы — clubs  Бубны — diamonds  Червы — hearts  Пики — spades
	
	output(cardsCount, cardName, cardNum);
	return 0;
}