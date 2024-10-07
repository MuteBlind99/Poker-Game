
#include <iostream>
#include "player.h"


#include "carte.h"
#include "Deck.h"

int hand1;
int hand2;
Player party;
//Value carte_field;
//Suit suit_;
//Player  player1;
//Player player2;




int main()
{
	Deck deck;
	deck.MakeDeck();

	deck.ShuffleDeck();

	Player player1;
	Player player2;



	for (int i = 0; i <= 1; i++)
	{
		player1.AddCard(deck.PickRemovedCard());
		player2.AddCard(deck.PickRemovedCard());
	}
	player1.DisplayHand();
	std::cout << '\n';
	player2.DisplayHand();

	if (player1.Hand().front().GetValueToInt() == player2.Hand().front().GetValueToInt())
	{
		std::cout << ""<< '\n';
	}
	else if (player1.Hand().front().GetValueToInt() > player2.Hand().front().GetValueToInt())
	{
		std::cout << "Player1 win" << '\n';
	}
	else if (player1.Hand().front().GetValueToInt() < player2.Hand().front().GetValueToInt())
	{
		std::cout << "Player2 win" << '\n';
	}






	/*Carte carte_1;
	Carte carte_2;
	Carte carte_3;
	Carte carte_4;
	Carte field_card;*/


	/*std::string<int>carte_p1 = 4;
	std::string<int>carte_p2 = 3;*/




	/*std::cout << "Player1 got a: " << carte_1.DrawCard() << " and " << carte_2.DrawCard() << '\n';

	std::cout << "player2 got a: " << carte_3.DrawCard() << " and " << carte_4.DrawCard() << '\n';

	for (int i = 0; i < field_card.decksize ;i++)
	{
		 field_card.FieldCard();
	}*/
	//std::cout << field_card.DrawCard() << std::endl;

	/*int Score_p1 = carte_1.value_()+ carte_2.value_();
	int Score_p2 = carte_3.value_() + carte_4.value_();*/

	//hand = (Carte)carte_1;
	//std::queue<int>deck;
	//for (auto player : carte_p1)
	//{
	//	//std::cout << ;
	//}
	/*Value carte_value1_p1 = (Value)carte_1.value_;
	Value carte_value2_p1 = (Value)carte_2.value_;
	Value carte_value1_p2 = (Value)carte_3.value_;
	Value carte_value2_p2 = (Value)carte_4.value_;*/
	//hand1 = carte_1.value_ + carte_2.value_;
	//hand2 = carte_3.value_ + carte_4.value_;
	//
	//// Vainqueur 
	//if (party.player_win(hand1,hand2))
	//	{
	//	std::cout << "Player1 had a " << carte_1.GetSuitString()<< " and " << carte_2.GetSuitString() << '\n';
	//	std::cout << "Player2 had a " << carte_3.GetSuitString() << " and " << carte_4.GetSuitString() << '\n';
	//	
	//	std::cout << "Player1 win";
	//}
	//else
	//{
	//	std::cout << "Player2 had a " << carte_3.GetSuitString() << " and " << carte_4.GetSuitString() << '\n';
	//	std::cout << "Player1 had a " << carte_1.GetSuitString() << " and " << carte_2.GetSuitString() << '\n';
	//	std::cout << "Player2 win";

	//}


}

