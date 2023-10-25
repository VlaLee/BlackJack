#pragma once

#include <string>

namespace constants {
	const unsigned short deck_size(52);
	const unsigned short max_suit(4);
	const unsigned short max_rank(13);
	const double default_bank(1000);
}

namespace playerChoices {
	const std::string YES_1("YES");
	const std::string YES_2("Yes");
	const std::string YES_3("yes");

	const std::string NO_1("NO");
	const std::string NO_2("No");
	const std::string NO_3("no");

	const std::string HIT_1("HIT");
	const std::string HIT_2("Hit");
	const std::string HIT_3("hit");

	const std::string STAND_1("STAND");
	const std::string STAND_2("Stand");
	const std::string STAND_3("stand");

	const std::string DOUBLE_1("DOUBLE");
	const std::string DOUBLE_2("Double");
	const std::string DOUBLE_3("double");
}