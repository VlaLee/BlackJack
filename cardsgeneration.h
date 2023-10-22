#pragma once

#include <string>
#include <array>
#include "mainstructures.h"
#include "constants.h"

unsigned short getCardValue(const Card& card);

std::string getCardName(const Card& card);

void print_card(const Card& card);

void print_deck(const std::array<Card, constants::deck_size>& deck);