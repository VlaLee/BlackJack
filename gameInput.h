#pragma once

#include <string>

bool is_answer_YES(std::string userAnswer);

bool is_answer_NO(std::string userAnswer);

bool is_answer_HIT(std::string userAnswer);

bool is_answer_STAND(std::string userAnswer);

bool is_answer_DOUBLE(std::string userAnswer);

bool is_digit(char symbol);

void getPlayerChoice(std::string& playerChoice);

void getPlayerChoiceYesNo(std::string& playerChoice);

void getPlayerChoiceDoubleNo(std::string& playerChoice);

void getPlayerChoiceHitStand(std::string& playerChoice);

void getPlayerBet(double& bet, double bank);