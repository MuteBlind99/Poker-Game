#include "player.h"

#include "Cards.h"


Player::Player() : high_card_(Cards(0,5))
{
}

void Player::AddCard(Cards carte)
{
	hand.push_back(carte);

}

void Player::DisplayHand()
{
	for (auto h : hand)
	{
		std::cout << h.GetValueToString() << " of " << h.GetSuitString() << '\n';
	}
}

void Player::RestHand()
{
	hand.clear();
	rankings_ = Rank::kNull;
}


void Player::RankToString()
{
	switch (rankings_)
	{
	case Rank::kStraight: std::cout << "Straight" << std::endl; break;
	case Rank::kDoublePair: std::cout << "Double Pair" << std::endl;  break;
	case Rank::kPair: std::cout << "Pair" << std::endl;  break;
	case Rank::kFlush: std::cout << "Flush" << std::endl;  break;
	case Rank::kRoyalFlush: std::cout << "Royal Flush" << std::endl;  break;
	case Rank::kFourOfKind: std::cout << "Four of kind" << std::endl;  break;
	case Rank::kTreeOfAKinf: std::cout << " Tree of a Kinf" << std::endl;  break;
	case Rank::kFullHouse: std::cout << "Fullhouse" << std::endl;  break;
	case Rank::kHighCard: std::cout << "High Card at " << high_card_.GetValueToString() << std::endl;  break;
	case Rank::kStraightFlush: std::cout << "Straight Flush" << std::endl;  break;
	}
}

int Player::RankToInt()
{
	switch (rankings_)
	{
	case Rank::kHighCard: return static_cast<int>(Rank::kHighCard);
	case Rank::kPair: return static_cast<int>(Rank::kPair);
	case Rank::kDoublePair: return static_cast<int>(Rank::kDoublePair);
	case Rank::kTreeOfAKinf: return static_cast<int>(Rank::kTreeOfAKinf);
	case Rank::kStraight: return static_cast<int>(Rank::kStraight);
	case Rank::kFlush: return static_cast<int>(Rank::kFlush);
	case Rank::kFullHouse: return static_cast<int>(Rank::kFullHouse);
	case Rank::kFourOfKind: return static_cast<int>(Rank::kFourOfKind);
	case Rank::kStraightFlush: return static_cast<int>(Rank::kStraightFlush);
	case Rank::kRoyalFlush: return  static_cast<int>(Rank::kRoyalFlush);
	}
	return {};
}



