#include "Rankings.h"

#include "Cards.h"
#include "Cards.h"
#include "player.h"

Cards::Value Rankings::Straight(Player& player, std::vector<Cards> dealer)
{
	std::vector<Cards>allcards = dealer;
	for (auto h : player.Hand())
	{
		allcards.emplace_back(h);
	}
	//Number order cards
	std::sort(allcards.begin(), allcards.end(), Cards::CardCompare);

	bool flag_Ace = false;
	int straight_count = 1;
	int old_card = 0;
	int nb_suit = 0;
	std::string old_suit;
	int player_rank;


	for (auto card : allcards)
	{
		//Player got a Ace ?
		if (card.value_ == Cards::Value::kAce)
		{
			flag_Ace = true;
			continue;
		}
		//Pair
		if (card.GetValueToInt() == old_card)
		{
			old_card = card.GetValueToInt();
		}
		//Next card follow
		else if (card.GetValueToInt() == old_card + 1)
		{
			straight_count = straight_count + 1;
			old_card = card.GetValueToInt();
		}
		//Straight break
		else if (old_card != card.GetValueToInt() && (straight_count < 5 || straight_count < 4 && !flag_Ace))
		{
			straight_count = 1;
			old_card = card.GetValueToInt();
		}
		else
		{

			old_card = card.GetValueToInt();
		}
	}

	bool real_straight = false;

	//Card suit vérification in hand of player
	for (auto hand : player.Hand())
	{
		if (hand.GetValueToInt() >= old_card - straight_count && hand.GetValueToInt() <= old_card)
		{
			real_straight = true;
		}
	}

	//Straight quinte
	if (straight_count == 4 && flag_Ace && real_straight)
	{
		if (old_card == 5 || old_card == 13)
		{
			player.rankings_ = Player::Rank::kStraight;
			return Cards::IntToEnumValue(old_card);

		}
	}
	//5 same suit
	else if (straight_count >= 5 && real_straight)
	{
		player.rankings_ = Player::Rank::kStraight;
		return Cards::IntToEnumValue(old_card);

	}
	//Highcard
	else if (player.Hand().front() > player.Hand().back())
	{
		if (player.Hand().back().value_ == Cards::Value::kAce)
		{
			return player.Hand().back().value_;
		}
		return player.Hand().front().value_;
	}
	else
	{
		return player.Hand().back().value_;
	}

	/*switch (suit)
	{
	case Player::Rank::kHighCard:
		old_suit = 1;
		nb_suit = nb_suit + 1;
		break;
	case Player::Rank::kPair:
		old_suit = 2;
		break;
	case Player::Rank::kDoublePair:
		break;
	case Player::Rank::kTreeOfAKinf:
		break;
	case Player::Rank::kStraight:
		break;
	case Player::Rank::kFlush:
		break;
	case Player::Rank::kFullHouse:
		break;
	case Player::Rank::kFourOfKind:
		break;
	case Player::Rank::kRoyalFlush:
		break;

	}*/

}

Cards::Value Rankings::DoublePair(Player& player, std::vector<Cards> dealer)
{
	std::vector<Cards>allcards = dealer;
	for (auto h : player.Hand())
	{
		allcards.emplace_back(h);
	}

	std::sort(allcards.begin(), allcards.end(), Cards::CardCompare);

	int pair_count = 0;
	int old_card = 0;
	int first_card = 0;

	for (auto card : allcards)
	{
		if (card.GetValueToInt() == first_card)
		{
			if (card.GetValueToInt() == old_card)
			{
				pair_count++;
				old_card = card.GetValueToInt();
			}
			else
			{
				old_card = card.GetValueToInt();
			}
		}
		else
		{
			if (card.GetValueToInt() == old_card)
			{
				pair_count++;
				old_card = card.GetValueToInt();
			}
			else
			{
				old_card = card.GetValueToInt();
				first_card = card.GetValueToInt();
			}

		}

	}

	switch (pair_count)
	{
	case 1:player.rankings_ = Player::Rank::kPair;
		return Cards::IntToEnumValue(old_card);
	case 3:
		player.rankings_ = Player::Rank::kDoublePair;
		return Cards::IntToEnumValue(old_card);
	case 4:
		player.rankings_ = Player::Rank::kFourOfKind;
		return Cards::IntToEnumValue(old_card);
	}
	return {};
}

Cards::Value Rankings::FullHouse(Player& player, std::vector<Cards> dealer)
{
	std::vector<Cards>allcards = dealer;
	for (auto h : player.Hand())
	{
		allcards.emplace_back(h);
	}

	std::sort(allcards.begin(), allcards.end(), Cards::CardCompare);

	int triple_count = 0;
	int pair_count = 0;
	int old_card = 0;
	int first_card = 0;
	for (auto card : allcards)
	{
		if (card.GetValueToInt() == first_card)
		{
			if (card.GetValueToInt() == old_card)
			{
				triple_count++;
				old_card = card.GetValueToInt();
			}
			else
			{
				pair_count++;
				old_card = card.GetValueToInt();
			}

		}
		else
		{
			if (card.GetValueToInt() == old_card)
			{
				old_card = card.GetValueToInt();
			}
			/*{
				old_card= card.GetValueToInt();
			}*/


			first_card = card.GetValueToInt();
		}


	}
	if (triple_count == 1)
	{
		switch (pair_count)
		{
		case 2:player.rankings_ = Player::Rank::kTreeOfAKinf;
			return Cards::IntToEnumValue(old_card);

		case 3:player.rankings_ = Player::Rank::kFullHouse;
			return Cards::IntToEnumValue(old_card);
		}

	}
	return {};
}
//Cards::Value Rankings::Flush(Player& player, std::vector<Cards> dealer)
//{
//	
//}
