#pragma once
#include "Cards.h"
#include "player.h"

class Rankings
{
public:
	Cards::Value Straight(Player& player, std::vector<Cards> dealer);
	Cards::Value DoublePair(Player& player, std::vector<Cards> dealer);
	Cards::Value FullHouse(Player& player, std::vector<Cards> dealer);
};


