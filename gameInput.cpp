#include <iostream>
#include <string>
#include "constants.h"

using namespace playerChoices;

bool is_answer_YES(std::string userAnswer) {
	return userAnswer == YES_1 || userAnswer == YES_2 || userAnswer == YES_3;
}

bool is_answer_NO(std::string userAnswer) {
	return userAnswer == NO_1 || userAnswer == NO_2 || userAnswer == NO_3;
}

bool is_answer_HIT(std::string userAnswer) {
	return userAnswer == HIT_1 || userAnswer == HIT_2 || userAnswer == HIT_3;
}

bool is_answer_STAND(std::string userAnswer) {
	return userAnswer == STAND_1 || userAnswer == STAND_2 || userAnswer == STAND_3;
}

bool is_answer_DOUBLE(std::string userAnswer) {
	return userAnswer == DOUBLE_1 || userAnswer == DOUBLE_2 || userAnswer == DOUBLE_3;
}

bool is_digit(char c) {
	return c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' ||
		c == '6' || c == '7' || c == '8' || c == '9';
}

void getPlayerChoice(std::string& playerChoice) {
	std::string tempString;
	std::cin >> tempString;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}
	else {
		std::cin.ignore(32767, '\n');
		playerChoice = tempString;
	}
}

void getPlayerChoiceYesNo(std::string& playerChoice) {
	while (true) {
		getPlayerChoice(playerChoice);

		if (is_answer_NO(playerChoice) || is_answer_YES(playerChoice))
			break;
		else
			std::cout << "Incorrect action, try again: ";
	}
}

void getPlayerChoiceDoubleNo(std::string& playerChoice) {
	while (true) {
		getPlayerChoice(playerChoice);

		if (is_answer_DOUBLE(playerChoice) || is_answer_NO(playerChoice))
			break;
		else
			std::cout << "Incorrect action, try again: ";
	}
}

void getPlayerChoiceHitStand(std::string& playerChoice) {
	while (true) {
		getPlayerChoice(playerChoice);

		if (is_answer_HIT(playerChoice) || is_answer_STAND(playerChoice))
			break;
		else
			std::cout << "Incorrect action, try again: ";
	}
}

void getPlayerBet(double& bet, double bank) {
	std::string tempString;

	std::cout << "Enter your bet amount: ";

	while (true) {
		bool flag = false;
		std::cin >> tempString;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Incorrect value, try again: ";
		}

		else {
			std::cin.ignore(32767, '\n');
			for (int i = 0; i < tempString.size(); i++)
				if (!is_digit(tempString[i]))
					flag = true;

			if (flag) {
				std::cout << "Incorrect value, try again: ";
				continue;
			}

			bet = stod(tempString);

			if (bet > bank)
				std::cout << "Your bet is more then your bank. Please enter your bet again: ";
			else if (bet < 0)
				std::cout << "Your bet is negative. Please enter your bet again: ";
			else if (bet == 0)
				std::cout << "Your bet can't equal to zero. Please enter your bet again: ";
			else
				break;
		}
	}
}