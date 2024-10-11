#pragma once
#include "Cards.h"
#include "player.h"

class Rankings
{
private:
	bool straight=false;
	bool flush =false ;
public:
	void HighCard(Player& player);
	void Straight(Player& player, std::vector<Cards>& player_hand, std::vector<Cards> dealer);
	void DoublePair(Player& player, std::vector<Cards> dealer);
	void FullHouse(Player& player, std::vector<Cards> dealer);
	void StraightFlush(Player& player, std::vector<Cards> dealer);
	void CheckHand(Player& player, std::vector<Cards> dealer);
	std::vector<Cards> Flush(Player& player, std::vector<Cards> dealer);
	void RoyalFlush(Player& player, std::vector<Cards> straight_flush);
};


