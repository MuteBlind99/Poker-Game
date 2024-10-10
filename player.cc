#include "player.h"

#include "Cards.h"



bool Player::player_win(int player_hand1, int player_hand2)
{










	if (player_hand1 > player_hand2)
	{
		return true;

	}
	else if (player_hand1 == player_hand2)
	{
		return true;
	}
	else
	{
		return false;
	}
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


std::string Player::RankToString()
{
	switch (rankings_)
	{
	case Rank::kStraight: return "Straight";
	case Rank::kDoublePair: return "Double Pair";
	case Rank::kPair: return "Pair";
	case Rank::kFlush: return "Double Pair";
	case Rank::kRoyalFlush: return "Royal Flush";
	case Rank::kFourOfKind: return "Four of kind";
	case Rank::kTreeOfAKinf: return " Tree of a Kinf";
	case Rank::kFullHouse: return "Fullhouse";



	default: return "High Card";
	}
	return {};
}

