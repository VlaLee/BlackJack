#include <iostream>
#include <array>
#include <string>
#include <vector>
#include "cardsgeneration.h"
#include "constants.h"
#include "mainstructures.h"
#include "output.h"


using namespace std;
using namespace cards_characteristics;
using namespace constants;

string userMessage = "";
long long int bank = 1000;
long long int bet = 0;

gameResult playBlackJack(array<Card, deck_size>& deck){
  cout << "Enter your bet amount: ";
  while(true){
	cin>>bet;
  	if(bet>bank){
		cout<<"Your bet is more then your bank. Please enter your bet again: ";
		
	}
	else if(bet<=0){
		cout<<"Your bet is negative. Please enter your bet again: ";
	}
		else break;
  }		
  snuffleDeck(deck);
  int playerScore = 0;
  int dilerScore = 0;
  vector <Card> playerCards;
  vector <Card> dilerCards;

  // Первая карта игроку
  int index = 0;
  playerScore += getCardValue(deck[index]);
  playerCards.push_back(deck[index]);
  output(playerCards,dilerCards);

  // Первая карта дилеру
  index = 1;
  dilerScore += getCardValue(deck[index]);
  dilerCards.push_back(deck[index]);
  output(playerCards,dilerCards);

  // Вторая карта игроку 
  index = 2;
  playerScore += getCardValue(deck[index]);
  playerCards.push_back(deck[index]);
  output(playerCards,dilerCards);
  index++;

  if (playerCards[0].rank == playerCards[1].rank == RANK_ACE)
    playerScore--;

  if (playerScore == 21 && dilerScore < 10) return WIN;

  else{
    userMessage = " ";
    if (playerScore == 10  || playerScore == 11){
      if (bank >= 2*bet){
        cout << "If you want to double your bet then enter 'Yes' otherwise 'No': ";
        cin >> userMessage;
        if (userMessage == "Yes")
          bet *= 2;
      }
      else{
        cout << "If you want all in then enter 'Yes' otherwise 'No': ";
        cin >> userMessage;
        if (userMessage == "Yes")
          bet = bank;
      }

      if (userMessage == "Yes"){
          playerScore += getCardValue(deck[index]);
          playerCards.push_back(deck[index]);
          index++;
          output(playerCards,dilerCards);
          if (playerScore > 21){
            return LOSE;
          }
      }

    else{
      while (true){
  userMessage = " ";
      cout << "If you want to get another card then enter 'Yes' otherwise 'No': ";
      cin >> userMessage;
      if (userMessage == "Yes"){
        playerScore += getCardValue(deck[index]);
        playerCards.push_back(deck[index]);
        index++;
        output(playerCards,dilerCards);
        if (playerScore > 21){
          return LOSE;
        }  
      } 
      if (userMessage == "No" || playerScore == 21){
        break;
      }
    }
  }
    }
    else if (userMessage != "Yes"){
      while (true){
  userMessage = " ";
      cout << "If you want to get another card then enter 'Yes' otherwise 'No': ";
      cin >> userMessage;
      if (userMessage == "Yes"){
        playerScore += getCardValue(deck[index]);
        playerCards.push_back(deck[index]);
        index++;
        output(playerCards,dilerCards);
        if (playerScore > 21){
          return LOSE;
        }  
      } 
      if (userMessage == "No"  || playerScore == 21){
        break;
      }
    }
  }
  
  // Вторая карта дилеру
  dilerScore += getCardValue(deck[index]);
  dilerCards.push_back(deck[index]);
  index++;
  output(playerCards,dilerCards);

  // Два туза у дилера
  if (dilerCards[0].rank == dilerCards[1].rank == RANK_ACE)
  dilerScore--;

  while (dilerScore < 17){
    dilerScore += getCardValue(deck[index]);
    dilerCards.push_back(deck[index]);
    index++;
    output(playerCards,dilerCards);
  }
  if (dilerScore > 21  || playerScore > dilerScore){
    return WIN;
  }
  else if (dilerScore == playerScore){
    return DRAW;
  }
  else {
    return LOSE;
  }
  return WIN;
}
}
int main() {

	system("cls");
  // Создали колоду
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
  	cout << "If you want to start the game enter 'Yes' otherwise 'No': ";
  	cin >> userMessage;
  	if (userMessage == "Yes"){
    cout << "Your bank: " << bank << endl;
    while (true){
	  if(bank==0){
		cout<<"Do u wanna get xtra money? Enter 'Yes' or 'No': ";
		cin>>userMessage;
		if(userMessage=="Yes"){
			bank=1000;
		}
		else {
			return 0;
		}
	  }
      int result = playBlackJack(gameDeck);
      if (result == 0){
        cout << "WIN" << endl;
        bank += bet;
      }
      if (result == 1){
        bank -= bet;
        cout << "LOSE" << endl;
      } 
      if (result == 2){
        cout << "DRAW" << endl;
      } 
      cout << "Your bank: " << bank << endl;
      cout << "If you want to play again enter 'Yes' otherwise 'No': ";
      cin >> userMessage;
      if (userMessage == "No") 
      break;
    }
  }
}
