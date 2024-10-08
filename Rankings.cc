#include "Rankings.h"

#include "player.h"


void Rankings::Straight(Player & player, std::vector<Cards> dealer)
{
	std::vector<Cards>allcards = dealer;
	for (auto h : player.Hand())
	{
		allcards.emplace_back(h);
	}
	std::sort(player.Hand().begin(), player.Hand().end(), Cards::CardCompare);

	bool flag_Ace = false;
	int straight_count = 0;
	int old_card = 0;
	Value value;

	for (auto card : allcards)
	{
		if (card.value_ == Value::kAce)
		{
			flag_Ace = true;
			continue;
		}

		if (card.GetValueToInt() == old_card + 1)
		{
			straight_count = straight_count + 1;
			old_card = card.GetValueToInt();
		}

		else if (old_card != card.GetValueToInt())
		{

			straight_count = 1;
			old_card = card.GetValueToInt();
		}
		if(straight_count==4 && flag_Ace)
		{
			if(old_card==5 || old_card==13)
			{
				player.rankings_ = Player::Rank::kStraight;
				
			}
		}
		else if(straight_count>=5)
		{
			player.rankings_ = Player::Rank::kStraight;
			
		}
	}


}

