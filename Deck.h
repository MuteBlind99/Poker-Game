#pragma once
#include "Cards.h"

class Deck
{
public:
	void MakeDeck();
	void DrawDeck();
	Cards PickRemovedCard();
	void ShuffleDeck();
	void DeckReset();
private:
	std::vector<Cards>Cartes;
};

