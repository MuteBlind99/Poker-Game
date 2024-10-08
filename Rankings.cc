#include "Rankings.h"


void Rankings::Straight(std::vector<Cards> hand, std::vector<Cards> dealer)
{
	std::vector<Cards>allcards = dealer;
	for (auto h : hand)
	{
		allcards.emplace_back(h);
	}
	std::sort(hand.begin(), hand.end(), Cards::CardCompare);
	bool flag_Ace = false;
	int straight_count = 0;
	int old_card = 0;
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

	}

}

