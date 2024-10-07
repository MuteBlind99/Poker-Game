#pragma once
#include "Carte.h"

class Deck
{
public:
	void MakeDeck();
	void DrawDeck();
	Carte PickRemovedCard();
	void ShuffleDeck();
private:
	std::vector<Carte>Cartes;
};

