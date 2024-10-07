
#include <iostream>
#include "player.h"


#include "carte.h"

int hand1;
int hand2;
Player party;
//Value carte_field;
//Suit suit;
//Player  player1;
//Player player2;




int main()
{
	Carte carte_1;
	Carte carte_2;
	Carte carte_3;
	Carte carte_4;
	Carte field_card;


	/*std::string<int>carte_p1 = 4;
	std::string<int>carte_p2 = 3;*/
	

	

	std::cout << "Player1 got a: " << carte_1.DrawCard() << " and " << carte_2.DrawCard() << '\n';

	std::cout << "player2 got a: " << carte_3.DrawCard() << " and " << carte_4.DrawCard() << '\n';

	for (int i = 0; i < field_card.decksize ;i++)
	{
		 field_card.FieldCard(); 
	}
	//std::cout << field_card.DrawCard() << std::endl;

	/*int Score_p1 = carte_1.carte_value()+ carte_2.carte_value();
	int Score_p2 = carte_3.carte_value() + carte_4.carte_value();*/

	//hand = (Carte)carte_1;
	//std::queue<int>deck;
	//for (auto player : carte_p1)
	//{
	//	//std::cout << ;
	//}
	/*Value carte_value1_p1 = (Value)carte_1.carte_value;
	Value carte_value2_p1 = (Value)carte_2.carte_value;
	Value carte_value1_p2 = (Value)carte_3.carte_value;
	Value carte_value2_p2 = (Value)carte_4.carte_value;*/
	hand1 = carte_1.carte_value + carte_2.carte_value;
	hand2 = carte_3.carte_value + carte_4.carte_value;
	
	// Vainqueur 
	if (party.player_win(hand1,hand2))
		{
		std::cout << "Player1 had a " << StringToValue(carte_1.carte_value) << " and " << StringToValue(carte_2.carte_value) << '\n';
		std::cout << "Player2 had a " << StringToValue(carte_3.carte_value) << " and " << StringToValue(carte_4.carte_value) << '\n';
		
		std::cout << "Player1 win";
	}
	else
	{
		std::cout << "Player2 had a " << StringToValue(carte_3.carte_value) << " and " << StringToValue(carte_4.carte_value) << '\n';
		std::cout << "Player1 had a " << StringToValue(carte_1.carte_value) << " and " << StringToValue(carte_2.carte_value) << '\n';
		std::cout << "Player2 win";
	}


}

