#include "Rankings.h"

#include "Cards.h"
#include "Cards.h"
#include "player.h"

void Rankings::HighCard(Player& player)
{
	if (player.Hand().front() > player.Hand().back()) {
		if (player.Hand().back().value_ == Cards::Value::kAce)
		{
			player.high_card_ = player.Hand().back();
		}
		player.high_card_ = player.Hand().front();
	}
	player.high_card_ = player.Hand().back();
}

void Rankings::Straight(Player& player, std::vector<Cards>& player_hand, std::vector<Cards> dealer)
{
	std::vector<Cards>allcards;
	straight = false;
	if (!flush)
	{
		allcards = dealer;
		for (auto h : player_hand)
		{
			allcards.emplace_back(h);
		}
	}
	else
	{
		allcards = player_hand;
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
		else if (straight_count < 5 || straight_count > 4 && !flag_Ace)
		{
			straight_count = 1;
			old_card = card.GetValueToInt();
		}
		else
		{

			old_card = card.GetValueToInt();
		}
	}

	//Straight quinte
	if (straight_count == 4 && flag_Ace)
	{
		if (old_card == 5 || old_card == 13)
		{
			straight = true;
			player.rankings_ = Player::Rank::kStraight;
			//player.high_card_.value_ = Cards::IntToEnumValue(old_card);

		}
	}
	//5 same suit
	else if (straight_count >= 5)
	{
		straight = true;
		player.rankings_ = Player::Rank::kStraight;
		//player.high_card_.value_ = Cards::IntToEnumValue(old_card);

	}
}

void Rankings::DoublePair(Player& player, std::vector<Cards> dealer)
{
	std::vector<Cards>allcards = dealer;
	for (auto h : player.Hand())
	{
		allcards.emplace_back(h);
	}

	std::sort(allcards.begin(), allcards.end(), Cards::CardCompare);

	int same_card = 0;
	int pair_card = 0;
	bool is_tree = false;
	int old_card = 0;

	for (auto card : allcards)
	{
		if (card.GetValueToInt() == old_card)
		{
			same_card++;
			if (same_card == 1)
			{
				pair_card++;
			}
			if(same_card >= 2)
			{
				is_tree = true;
				break;
			}
		}
		else
		{
			old_card = card.GetValueToInt();
			same_card = 0;
		}
	}

	if (is_tree)
	{
		player.rankings_ = Player::Rank::kTreeOfAKinf;
	}
	else if(pair_card >= 2 && !straight && !flush)
	{
		player.rankings_ = Player::Rank::kDoublePair;
	}
	else if(pair_card == 1 && !straight && !flush)
	{
		player.rankings_ = Player::Rank::kPair;
	}
}

void Rankings::FullHouse(Player& player, std::vector<Cards> dealer)
{
	std::vector<Cards>allcards = dealer;
	for (auto h : player.Hand())
	{
		allcards.emplace_back(h);
	}

	std::sort(allcards.begin(), allcards.end(), Cards::CardCompare);

	int same_card = 0;
	int count_pair = 0;
	bool is_tree = false;
	bool is_full = false;
	bool is_quads = false;
	int old_card = 0;

	for (auto card : allcards)
	{
		if (card.GetValueToInt() == old_card)
		{
			same_card++;
			if (same_card == 1)
			{
				count_pair++;
			}
			if (same_card == 2 && !is_full)
			{
				is_tree = true;
				is_full = true;
				count_pair = 0;
			}
			if (same_card >= 3)
			{
				is_quads = true;
				break;
			}
		}
		else
		{
			old_card = card.GetValueToInt();
			same_card = 0;
		}
	}

	if (is_quads)
	{
		player.rankings_ = Player::Rank::kFourOfKind;
	}

	if (count_pair >= 1 && is_tree && !is_quads)
	{
		player.rankings_ = Player::Rank::kFullHouse;
	}

	

}

void Rankings::StraightFlush(Player& player, std::vector<Cards> dealer)
{
	std::vector<Cards>v_straight_flush = Flush(player, dealer);
	if (flush)
	{
		Straight(player, v_straight_flush, dealer);
	}
	else
	{
		Straight(player, player.Hand(), dealer);
	}
	if (flush && straight)
	{
		player.rankings_ = Player::Rank::kStraightFlush;
		RoyalFlush(player, v_straight_flush);
	}
}

void Rankings::CheckHand(Player& player, std::vector<Cards> dealer)
{
	player.rankings_ = Player::Rank::kHighCard;
	HighCard(player);
	StraightFlush(player, dealer);
	if (player.rankings_ != Player::Rank::kStraightFlush || player.rankings_ != Player::Rank::kRoyalFlush)
	{
		FullHouse(player, dealer);//Full or Quad
	}
	if(player.rankings_ == Player::Rank::kHighCard)
	{
		DoublePair(player, dealer);
	}
}

std::vector<Cards> Rankings::Flush(Player& player, std::vector<Cards> dealer)
{
	std::vector<Cards>allcards = dealer;
	for (auto h : player.Hand())
	{
		allcards.emplace_back(h);//Add player in vector Card
	}

	std::vector<Cards>v_Club;
	std::vector<Cards>v_Square;
	std::vector<Cards>v_Diamond;
	std::vector<Cards>v_Heart;
	auto suit_return = Cards::Suit::kNoSuit;
	bool is_flush = false;
	flush = false;
	for (auto card : allcards)
	{
		switch (card.suit_)
		{
		case Cards::Suit::kClub:
			v_Club.emplace_back(card);
			if (!is_flush && v_Club.size() >= 5)
			{
				suit_return = Cards::Suit::kClub;
				is_flush = true;
			}
			break;

		case Cards::Suit::kSquare:
			v_Square.emplace_back(card);
			if (!is_flush && v_Square.size() >= 5)
			{
				suit_return = Cards::Suit::kSquare;
				is_flush = true;
			}
			break;

		case Cards::Suit::kDiamond:
			v_Diamond.emplace_back(card);
			if (!is_flush && v_Diamond.size() >= 5)
			{
				suit_return = Cards::Suit::kDiamond;
				is_flush = true;
			}
			break;

		case Cards::Suit::kHeart:
			v_Heart.emplace_back(card);
			if (!is_flush && v_Heart.size() >= 5)
			{
				suit_return = Cards::Suit::kHeart;
				is_flush = true;
			}
			break;

		}
	}
	if (is_flush)
	{
		flush = true;
		player.rankings_ = Player::Rank::kFlush;
	}
	switch (suit_return)
	{
	case Cards::Suit::kClub:
		return v_Club;
	case Cards::Suit::kSquare:
		return v_Square;
	case Cards::Suit::kDiamond:
		return v_Diamond;
	case Cards::Suit::kHeart:
		return v_Heart;
	case Cards::Suit::kNoSuit:
		break;
	}
	return {};
}
void Rankings::RoyalFlush(Player& player, std::vector<Cards>straight_flush)
{
	int royal_flush = 0;
	for (auto card : straight_flush)
	{
		switch (card.value_)
		{
		case Cards::Value::kAce:
			royal_flush++;
			break;
		case Cards::Value::kKing:
			royal_flush++;
			break;
		case Cards::Value::kQueen:
			royal_flush++;
			break;
		case Cards::Value::kJack:
			royal_flush++;
			break;
		case Cards::Value::k10:
			royal_flush++;
			break;
		default:
			royal_flush = 0;
			break;

		}
	}
	if (royal_flush >= 5)
	{
		player.rankings_ = Player::Rank::kRoyalFlush;
	}
}