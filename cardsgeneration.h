#pragma once

#include <string>
#include <array>
#include "mainstructures.h"
#include "constants.h"

void setRandomSettings();

int getRandomNumber(int min, int max);

void swapCard(Card& card_x, Card& card_y);

void snuffleDeck(std::array<Card, constants::deck_size>& deck);

unsigned short getCardValue(const Card& card);

std::string getCardName(const Card& card);

void printCard(const Card& card);

void printDeck(const std::array<Card, constants::deck_size>& deck);

void initializeClosedCard(Card& closedCard);