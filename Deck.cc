#include "Deck.h"



void Deck::MakeDeck()
{
	for (int color = 0; color <= 3; color++)
	{
		for (int value=1;value<=13;value++ )
		{
			Cartes.emplace_back(value, color);
		}
	}

}

void Deck::DrawDeck()
{
	for(auto c:Cartes)
	{
		std::cout << c.GetValueToString()<< " of "<< c.GetSuitString()<<'\n';
	}
}

Cards Deck::PickRemovedCard()
{
	Cards carte = Cartes.front();
	Cartes.erase(Cartes.begin());
	return carte;
}

void Deck::ShuffleDeck()
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::shuffle(Cartes.begin(), Cartes.end(),generator);
}

void Deck::DeckReset()
{
	Cartes.clear();
}
