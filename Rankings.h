#pragma once
#include "Cards.h"

class Rankings
{
public:
	enum class Rank
	{
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
	void Straight(std::vector<Cards> hand, std::vector<Cards> dealer);
	Rank rank_;
};


