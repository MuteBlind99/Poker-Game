#pragma once
#include "Cards.h"
#include "Rankings.h"

//Value card;

class Player
{
private:
	std::vector<Cards>hand;
	//const Value new_card = card;
public:
	//void take_card( Value new_card);
	int score_=0;
	bool player_win(int player_hand1, int player_hand2);
	void AddCard(Cards carte);
	void DisplayHand();
	std::vector<Cards>Hand()
	{
		return  hand;
	}
	int PlayerHandStraight(Player playerhand, Player dealerhand);
	Rankings rankings_;
};

