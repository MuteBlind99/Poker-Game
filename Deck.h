#pragma once
#include "Cards.h"

class Deck
{
public:
	void MakeDeck();
	void DrawDeck();
	Cards PickRemovedCard();
	void ShuffleDeck();
private:
	std::vector<Cards>Cartes;
};

