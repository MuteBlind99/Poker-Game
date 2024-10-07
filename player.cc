#include "player.h"

#include "Carte.h"
#include <cstdlib>


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