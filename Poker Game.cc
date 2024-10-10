
#include <iostream>
#include "player.h"


#include "Cards.h"
#include "Deck.h"
#include "Rankings.h"

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

	Player player1;
	Player player2;
	Player dealer;
	Rankings rank_player;

	Player::Rank rank_;

	int round = 0;
	do
	{
		deck.MakeDeck();

		deck.ShuffleDeck();
		//Players draw cards
		for (int i = 0; i <= 1; i++)
		{
			player1.AddCard(deck.PickRemovedCard());
			player2.AddCard(deck.PickRemovedCard());
		}
		std::cout << "You got a " << '\n';
		player1.DisplayHand();
		std::cout << '\n';

		std::cout << "Other player got a " << '\n';
		player2.DisplayHand();
		std::cout << '\n';


		//Field Card
		for (int i = 0; i <= 4; i++)
		{
			dealer.AddCard(deck.PickRemovedCard());
		}


		std::cout << "Card on field : " << '\n';
		dealer.DisplayHand();
		std::cout << '\n';


		Cards::Value value = rank_player.DoublePair(player1, dealer.Hand());

		rank_ = player1.rankings_;

		round++;
		std::cout << "Round : " << std::endl << round << std::endl;
		std::cout << "Card : " << static_cast<int>(value) << std::endl;
		std::cout << player1.RankToString() << std::endl << std::endl;

		player1.RestHand();
		player2.RestHand();
		dealer.RestHand();
		deck.DeckReset();
	}
	while (rank_ != Player::Rank::kDoublePair);




	////Who win the party ?
	//if (player1.Hand().front().GetValueToInt() == player2.Hand().front().GetValueToInt())
	//{
	//	std::cout << "Same suite" << '\n';
	//}
	//else if (player1.Hand().front().GetValueToInt() > player2.Hand().front().GetValueToInt())
	//{
	//	std::cout << "Player1 win" << '\n';
	//}
	//else if (player1.Hand().front().GetValueToInt() < player2.Hand().front().GetValueToInt())
	//{

	//	std::cout << "Player2 got" << '\n';
	//	std::cout << "Player2 win" << '\n';
	//}
	//if (player1.rankings_ > player2.rankings_)
	//{
	//	
	//}





		/*Cards carte_1;
		Cards carte_2;
		Cards carte_3;
		Cards carte_4;
		Cards field_card;*/


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

		//hand = (Cards)carte_1;
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