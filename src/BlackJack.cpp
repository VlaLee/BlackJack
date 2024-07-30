#include <iostream>
#include <array>
#include <string>
#include <vector>
#include "../include/cardsgeneration.h"
#include "../include/constants.h"
#include "../include/mainstructures.h"
#include "../include/gameOutput.h"
#include "../include/gameInput.h"

using namespace std;
using namespace cards_characteristics;
using namespace constants;

gameResult insuranceScenario(array<Card, deck_size>& deck, unsigned short& playerScore, unsigned short& dealerScore, vector <Card>& playerCards, vector <Card>& dealerCards, double &bet, double &bank) {
    string userMessage;
    
    if (playerScore == 21) {
        cout << "First dealer's card is Ace and you have 21. " <<
            "Do you want to get an immediate win ? Enter 'Yes' or 'No': ";
        getPlayerChoiceYesNo(userMessage);

        if (is_answer_YES(userMessage)) 
            return WIN;
        else if (is_answer_NO(userMessage)) {
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
        getPlayerChoiceYesNo(userMessage);

        if (is_answer_YES(userMessage)) {
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
    return CONTINUE;
}

gameResult doubleDownScenario(array<Card, deck_size>& deck, unsigned short& playerScore, unsigned short& index, unsigned short& dealerScore, vector <Card>& playerCards, vector <Card>& dealerCards, double& bet, double& bank, bool &isDD) {
    string userMessage;

    if (bank >= 2 * bet) {
        cout << "If you want to double your bet then enter 'Double' otherwise 'No': ";
        getPlayerChoiceDoubleNo(userMessage);

        if (is_answer_DOUBLE(userMessage)) {
            bet *= 2;
            isDD = false;
        }
    }

    else {
        cout << "If you want all in then enter 'Yes' otherwise 'No': ";
        getPlayerChoiceYesNo(userMessage);

        if (is_answer_YES(userMessage)) {
            bet = bank;
            isDD = false;
        }
    }

    if (isDD==false) {
        playerScore += getCardValue(deck.at(4));
        playerCards.push_back(deck.at(4));
        
        output(playerCards, dealerCards);
         cout<<"Player: "<<playerScore<<"\tDealer: "<<dealerScore<<endl;

        if (playerScore > 21)
            return LOSE;
    }

    return CONTINUE;
}

gameResult playBlackJack(array<Card, deck_size>& deck, double &bet, double &bank) {
    string userMessage;	

    snuffleDeck(deck);

    unsigned short playerScore = 0;
    unsigned short dealerScore = 0;

    vector <Card> playerCards;
    vector <Card> dealerCards;

    bool isDD = true;

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
        gameResult tempResult = insuranceScenario(deck, playerScore, dealerScore, playerCards, dealerCards, bet, bank);
        if (tempResult != CONTINUE)
            return tempResult;
    }

    if (playerScore == 21 && dealerScore < 10) {
        bet *= 1.5;
        return WIN;
    }

    if (playerScore == 10  || playerScore == 11) {
       gameResult tempResult = doubleDownScenario(deck, playerScore, dealerScore, index, playerCards, dealerCards, bet, bank, isDD);
       if(isDD==false){
            index++;
       }
       if (tempResult != CONTINUE)
           return tempResult;
    }

    if (isDD && playerScore < 21) {
        while (true) {
            cout << "If you want to get another card then enter "<<
                "'Hit' otherwise 'Stand': ";
            getPlayerChoiceHitStand(userMessage);

            if (is_answer_HIT(userMessage)) {
                playerScore += getCardValue(deck.at(index));
                playerCards.push_back(deck.at(index));
                index++;
                output(playerCards,dealerCards);


                if (playerScore > 21) {
                    return LOSE;
                }  
            }

            if (is_answer_STAND(userMessage) || playerScore == 21) {
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
    if (dealerCards.at(0).rank == RANK_ACE && dealerCards.at(1).rank == RANK_ACE) {
        dealerScore--;
    }
    
    if (playerScore == 21 && dealerScore != 21 && playerCards.size() == 2) {
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

    double bank = default_bank;
    double bet;

    string userMessage;
    cout << "If you want to start the game enter 'Yes' otherwise 'No': ";
    getPlayerChoiceYesNo(userMessage);
    if (!is_answer_YES(userMessage)) 
        return NO_ERRORS;

    cout << "Your bank: " << bank << endl;

    while (true) {
        if (bank == 0) {
            cout << "Do u wanna get extra money? Enter 'Yes' or 'No': ";
            getPlayerChoiceYesNo(userMessage);
            if (is_answer_YES(userMessage))
                bank = default_bank;
            else
                break;
        }
      
        getPlayerBet(bet, bank);
        gameResult result = playBlackJack(gameDeck, bet, bank);

        if (result == WIN) {
            bank += bet;
            cout << "WIN" << endl;
        }
        if (result == LOSE) {
            bank -= bet;
            cout << "LOSE" << endl;
        } 
        if (result == DRAW) {
            cout << "DRAW" << endl;
        }

        cout << "Your bank: " << bank << "; bet: " << bet << endl;
        cout << "If you want to play again enter 'Yes' otherwise 'No': ";

        getPlayerChoiceYesNo(userMessage);

        if (is_answer_NO(userMessage)) {
            cout << "Thanks for playing!";
            break;
        }
	}

    return NO_ERRORS;
}
