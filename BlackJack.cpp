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

long long bank = 1000;
long long bet = 0;

gameResult insuranceScenario(array<Card, deck_size>& deck, int playerScore, int dealerScore, vector <Card> playerCards, vector <Card> dealerCards) {
    string userMessage;
    
    if (playerScore == 21) {
        cout << "First dealer's card is Ace and you have 21. " <<
            "Do you want to get an immediate win ? Enter 'Yes' or 'No': ";
        cin >> userMessage;

        if (userMessage == "Yes") {
            return WIN;
        }
        else if (userMessage == "No") {
            dealerCards.erase(dealerCards.end() - 1);

            // Вторая карта дилеру
            dealerScore += getCardValue(deck.at(3));
            dealerCards.push_back(deck.at(3));
            output(playerCards, dealerCards);

            if (dealerScore > 20) {
                return DRAW;
            }
            else {
                bet *= 1.5;
                return WIN;
            }
        }
    }

    else if (bank > bet * 1.5) {
        cout << "First dealer's card is Ace. Do You wanna make an insurance bet? " <<
            "Enter 'Yes' or 'No': ";
        cin >> userMessage;

        if (userMessage == "Yes") {
            dealerCards.erase(dealerCards.end() - 1);

            // Вторая карта дилеру
            dealerScore += getCardValue(deck.at(3));
            dealerCards.push_back(deck.at(3));
            output(playerCards, dealerCards);

            if (dealerScore > 20)
                return DRAW;
            else {
                bank -= bet / 2;
                return CONTINUE;
            }
        }
    }
}

gameResult playBlackJack(array<Card, deck_size>& deck) {
    string userMessage;

    cout << "Enter your bet amount: ";

    while (true) {
	    cin >> bet;

        if (bet > bank)
		    cout << "Your bet is more then your bank. Please enter your bet again: ";
	    else if (bet <= 0)
		    cout << "Your bet is negative. Please enter your bet again: ";
	    else 
            break;
    }	

    snuffleDeck(deck);

    unsigned short playerScore = 0;
    unsigned short dealerScore = 0;
    vector <Card> playerCards;
    vector <Card> dealerCards;

    // Первая карта игроку
    unsigned short index = 0;
    playerScore += getCardValue(deck.at(index));
    playerCards.push_back(deck.at(index));

    // Первая карта дилеру
    index++;
    dealerScore += getCardValue(deck.at(index));
    dealerCards.push_back(deck.at(index));

    // Вторая карта игроку 
    index++;
    playerScore += getCardValue(deck.at(index));
    playerCards.push_back(deck.at(index));
    output(playerCards, dealerCards);

    index += 2;
    Card closedCard;
    initializeClosedCard(closedCard);
    dealerCards.push_back(closedCard);
    output(playerCards, dealerCards);

    if (playerCards.at(0).rank == RANK_ACE && playerCards.at(1).rank == RANK_ACE)
        playerScore--;

    if (dealerScore == 11) {
        gameResult tempResult = insuranceScenario(deck, playerScore, dealerScore, playerCards, dealerCards);
        if (tempResult != CONTINUE)
            return tempResult;
    }

    if (playerScore == 21 && dealerScore < 10) {
        bet *= 1.5;
        return WIN;
    }

    if (playerScore == 10  || playerScore == 11) {
        if (bank >= 2 * bet) {
            cout << "If you want to double your bet then enter " << 
                "'Yes' otherwise 'No': ";
            cin >> userMessage;

            if (userMessage == "Yes")
                bet *= 2;
        }

        else {
            cout << "If you want all in then enter 'Yes' otherwise 'No': ";
            cin >> userMessage;

            if (userMessage == "Yes")
                bet = bank;
        }

        if (userMessage == "Yes") {
            playerScore += getCardValue(deck.at(index));
            playerCards.push_back(deck.at(index));
            index++;
            output(playerCards, dealerCards);

            if (playerScore > 21)
                return LOSE;
        }

        else if (playerScore < 21) {
            while (true) {
                cout << "If you want to get another card then enter "<<
                    "'Yes' otherwise 'No': ";
                cin >> userMessage;
                if (userMessage == "Yes") {
                    playerScore += getCardValue(deck.at(index));
                    playerCards.push_back(deck.at(index));
                    index++;
                    output(playerCards, dealerCards);

                    if (playerScore > 21){
                    return LOSE;
                    }
                }
                if (userMessage == "No" || playerScore == 21) {
                    break;
                }
            }
        }
    }

    else if (userMessage != "Yes" && playerScore < 21) {
        while (true) {
            cout << "If you want to get another card then enter "<<
                "'Yes' otherwise 'No': ";
            cin >> userMessage;

            if (userMessage == "Yes") {
                playerScore += getCardValue(deck.at(index));
                playerCards.push_back(deck.at(index));
                index++;
                output(playerCards,dealerCards);

                if (playerScore > 21) {
                    return LOSE;
                }  
            }

            if (userMessage == "No"  || playerScore == 21) {
                break;
            }
        }
    }

    if (dealerCards.at(1).rank == RANK_UNKNOWN) {
        dealerCards.erase(dealerCards.end() - 1);
        dealerScore += getCardValue(deck.at(3));
        dealerCards.push_back(deck.at(3));
        output(playerCards, dealerCards);
    }
    

    // Два туза у дилера
    if (dealerCards.at(0).rank == dealerCards.at(1).rank == RANK_ACE) {
        dealerScore--;
    }
    
    if(playerScore == 21 && dealerScore != 21 && playerCards.size() == 2) {
        bet *= 1.5;
        return WIN;
    }

    while (dealerScore < 17) {
        dealerScore += getCardValue(deck.at(index));
        dealerCards.push_back(deck.at(index));
        index++;
        output(playerCards, dealerCards);
    }

    if (dealerScore > 21  || playerScore > dealerScore)
        return WIN;
    else if (dealerScore == playerScore)
        return DRAW;
    else
        return LOSE;
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
  if (userMessage == "Yes") {
    cout << "Your bank: " << bank << endl;

    while (true) {
      if (bank==0) {
        cout<<"Do u wanna get xtra money? Enter 'Yes' or 'No': ";

        while(true) {
          cin>>userMessage;
          if (userMessage=="Yes") {
            bank=1000;
            break;
          }
          else if (userMessage=="No") {
            return 0;
          }
            else {
              cout<<"Incorrect input. Please try again: 'Yes' or 'No': ";
            }
        }	
      }
      
      int bank2=bank;
      int result = playBlackJack(gameDeck);

      if (result == 0) {
        cout << "WIN" << endl;
        bank += bet;
      }
      if (result == 1) {
        bank -= bet;
        cout << "LOSE" << endl;
      } 
      if (result == 2) {
        cout << "DRAW" << endl;
      }

      cout << "Your bank: " << bank << " prev bank: "<<bank2<<" bet: "<<bet<<endl;
      cout << "If you want to play again enter 'Yes' otherwise 'No': ";

      while (true) {
        cin >> userMessage;

        if (userMessage == "No") {
          return 0;
        }
        else if (userMessage=="Yes") {
          break;
        }
        else {
          cout<<"Incorrect input. Please try again: 'Yes' or 'No': ";
        }
      }	
	  }
  }
}
