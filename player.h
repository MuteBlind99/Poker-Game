#pragma once
#include "Cards.h"


//Value card;

class Player
{
private:
	std::vector<Cards>hand;
	//const Value new_card = card;
public:
	Player() = default;
	enum class Rank
	{
		kNull,
		kHighCard,
		kPair,
		kDoublePair,
		kTreeOfAKind,
		kStraight,
		kFlush,
		kFullHouse,
		kFourOfKind,
		kStraightFlush,
		kRoyalFlush,

	};
	int score_=0;
	bool player_win(int player_hand1, int player_hand2);
	void AddCard(Cards carte);
	void DisplayHand();
	std::vector<Cards>Hand()
	{
		return  hand;
	}
	int PlayerHandStraight(Player playerhand, Player dealerhand);
	Rank rankings_;
};

