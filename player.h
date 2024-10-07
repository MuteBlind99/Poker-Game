#pragma once
#include "Carte.h"

//Value card;

class Player
{
private:
	std::vector<Carte>hand;
	//const Value new_card = card;
public:
	//void take_card( Value new_card);
	bool player_win(int player_hand1, int player_hand2);
	void AddCard(Carte carte);
	void DisplayHand();
	std::vector<Carte>Hand()
	{
		return  hand;
	}
	
};

