
#include <iostream>
#include "player.h"
#include <queue>

#include "carte.h"

Carte hand;
Player party;
//Value carte_field;
//Suit suit;
//Player  player1;
//Player player2;

int main()
{
	/*std::string<int>carte_p1 = 4;
	std::string<int>carte_p2 = 3;*/
	int carte_1 =4;
	int carte_2 = 8;
	int carte_3 = 3;
	int carte_4 = 7;
	int carte_p1 = carte_1 + carte_2;
	int carte_p2 = carte_3 + carte_4;
	hand = (Carte)carte_1;
	//std::queue<int>deck;
	//for (auto player : carte_p1)
	//{
	//	//std::cout << ;
	//}

	// Vainqueur 
	if (party.player_win(carte_p1, carte_p2))
	{
		std::cout << "Player1 had a " << carte_1 << '\t' << carte_2 << '\n';
		std::cout << "Player2 had a " << carte_3 << '\t' << carte_4 << '\n';
		//std::cout << "Player1 had a " << (int)hand << '\t' << carte_2 << '\n';
		std::cout << "Player1 win";
	}
	else
	{
		std::cout << "Player2 had a " << carte_3 << '\t' << carte_4 << '\n';
		std::cout << "Player1 had a " << carte_1 << '\t' << carte_2 << '\n';
		std::cout << "Player2 win";
	}


}

