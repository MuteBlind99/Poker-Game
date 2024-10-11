
#include <iostream>
#include "player.h"


#include "Cards.h"
#include "Deck.h"
#include "Rankings.h"


void NewRound(Deck& deck, Player& player1, Player& player2, Player& dealer)
{
	std::cout << std::endl << std::endl << "New Game" << std::endl << std::endl;

	player1.RestHand();
	player2.RestHand();
	dealer.RestHand();
	deck.DeckReset();
	deck.MakeDeck();
	deck.ShuffleDeck();
}

void DrawCard(Deck& deck, Player& player1, Player& player2)
{
	//Players draw cards
	for (int i = 0; i <= 1; i++)
	{
		player1.AddCard(deck.PickRemovedCard());
		player2.AddCard(deck.PickRemovedCard());
	}
}

void DisplayHandPlayer(Player& player1, Player& player2)
{
	std::cout << "Hand Player 1 : " << std::endl;
	player1.DisplayHand();

	std::cout << std::endl << "Hand bot : " << std::endl;
	player2.DisplayHand();
}

void Flop(Deck& deck, Player& dealer)
{
	for (int i = 0; i < 3; ++i)
	{
		dealer.AddCard(deck.PickRemovedCard());
	}
}

void DisplayTable(Player& player1, Player& bot, Player& dealer)
{
	DisplayHandPlayer(player1, bot);

	std::cout << std::endl;
	dealer.DisplayHand();
	std::cout << std::endl;
}

void CheckAllHand(Player& player1, Player& bot, Player& dealer, Rankings& rank_player)
{
	rank_player.CheckHand(player1, dealer.Hand());
	rank_player.CheckHand(bot, dealer.Hand());
}

void DisplayRank(Player& player1, Player& bot)
{
	std::cout << "Rank player 1 : " << std::endl;
	player1.RankToString();
	std::cout << std::endl << std::endl;
	std::cout << "Rank bot : " << std::endl;
	bot.RankToString();
	std::cout << std::endl << std::endl;
}

int main()
{
	Deck deck;
	Player player1;
	Player bot;
	Player dealer;
	Rankings rank_player;
	bool game_over = false;

	do
	{
		NewRound(deck, player1, bot, dealer);

		DrawCard(deck, player1, bot);

		DisplayHandPlayer(player1, bot);

		Flop(deck, dealer);

		DisplayTable(player1, bot, dealer);

		//Turn
		dealer.AddCard(deck.PickRemovedCard());

		DisplayTable(player1, bot, dealer);

		//River
		dealer.AddCard(deck.PickRemovedCard());

		DisplayTable(player1, bot, dealer);

		CheckAllHand(player1, bot, dealer, rank_player);

		DisplayRank(player1, bot);

		if (player1.RankToInt() > bot.RankToInt())
		{
			std::cout << "Player 1 wins" << std::endl;
		}
		else if(player1.RankToInt() < bot.RankToInt())
		{
			std::cout << "bot wins" << std::endl;
		}
		else if(player1.RankToInt() == bot.RankToInt())
		{
			if (player1.high_card_.GetValueToInt() > bot.high_card_.GetValueToInt())
			{
				if (bot.high_card_.GetValueToInt() == 1)
				{
					std::cout << "bot wins" << std::endl;
				}
				else
				{
					std::cout << "Player 1 wins" << std::endl;
				}
			}
			else if (player1.high_card_.GetValueToInt() < bot.high_card_.GetValueToInt())
			{
				if (player1.high_card_.GetValueToInt() == 1)
				{
					std::cout << "Player 1 wins" << std::endl;
				}
				else
				{
					std::cout << "bot wins" << std::endl;
				}
			}
			else if(player1.high_card_.GetValueToInt() == bot.high_card_.GetValueToInt())
			{
				std::cout << "It's a tie" << std::endl;
			}
		}

		game_over = true;
	}
	while (!game_over);


	system("pause");
}
