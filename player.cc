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


