
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
	int bank = 10;
	int player_bank = bank;
	int bot_bank = bank;
	bool game_over = false;
	char reset_button;
	int bet = 0;
	int bot_bet = 0;
	bool reset_party = true;
	std::cout << "Welcome to the Poker game";
	do
	{

		NewRound(deck, player1, bot, dealer);

		DrawCard(deck, player1, bot);

		DisplayHandPlayer(player1, bot);

		Flop(deck, dealer);//3 cards 

		DisplayTable(player1, bot, dealer);


		while (bot_bet < 1)
		{
			std::cout << "What's your bet ? [1] [3] [5] [10]";
			std::cin >> bet;
			switch (bet)
			{
			case 1: bot_bet = bet; break;
			case 3:bot_bet = bet; break;
			case 5:bot_bet = bet; break;
			case 10:bot_bet = bet; break;
			default: std::cout << "Invalid Command" << std::endl;
				bet = 0;
				break;
			}
		}



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
			player_bank = player_bank + bot_bet;
			bot_bank = bot_bank - bet;
			std::cout << "Player 1 wins " << bot_bet << std::endl;
			bet = 0;
			bot_bet = 0;
		}
		else if (player1.RankToInt() < bot.RankToInt())
		{
			player_bank = player_bank - bot_bet;
			bot_bank = bot_bank + bet;
			std::cout << "bot wins " << bet << std::endl;
			bet = 0;
			bot_bet = 0;
		}
		else if (player1.RankToInt() == bot.RankToInt())
		{
			if (player1.high_card_.GetValueToInt() > bot.high_card_.GetValueToInt())
			{
				if (bot.high_card_.GetValueToInt() == 1)
				{
					player_bank = player_bank - bot_bet;
					bot_bank = bot_bank + bet;
					std::cout << "bot wins " << bet << std::endl;
					bet = 0;
					bot_bet = 0;
				}
				else
				{
					player_bank = player_bank + bot_bet;
					bot_bank = bot_bank - bet;
					std::cout << "Player 1 wins " << bot_bet << std::endl;
					bet = 0;
					bot_bet = 0;
				}
			}
			else if (player1.high_card_.GetValueToInt() < bot.high_card_.GetValueToInt())
			{
				if (player1.high_card_.GetValueToInt() == 1)
				{
					player_bank = player_bank + bot_bet;
					bot_bank = bot_bank - bet;
					std::cout << "Player 1 wins " << bot_bet << std::endl;
					bet = 0;
					bot_bet = 0;

				}
				else
				{
					player_bank = player_bank - bot_bet;
					bot_bank = bot_bank + bet;
					
					std::cout << "bot wins " << bet << std::endl;
					bet = 0;
					bot_bet = 0;
				}
			}
			else if (player1.high_card_.GetValueToInt() == bot.high_card_.GetValueToInt())
			{
				player_bank = player_bank - bot_bet;
				bot_bank = bot_bank + bet;
				
				std::cout << "It's a tie" << std::endl;
				bet = 0;
				bot_bet = 0;
			}
		}

		std::cout << "Player1 got : " << player_bank << std::endl;
		std::cout << "Bot got : " << bot_bank << std::endl;
		if (player_bank <= 0)
		{
			std::cout << "Game Over"<<std::endl;
			game_over = true;
		}
		else if (bot_bank <= 0)
		{
			std::cout << "Game Over" << std::endl;
			game_over = true;
		}


		if (game_over)
		{
			while (reset_party)
			{
				std::cout << "Do you to play again ? [y/Y]Yes  [n/N]No" << std::endl;
				std::cin >> reset_button;
				if(reset_button=='y' || reset_button=='Y')
				{
					game_over = false;
				}

				switch (reset_button)
				{
				case 'y': case'Y':
					reset_party = false;
					break;

				case 'n': case'N':
					std::cout << "Bye bye" << std::endl;
					reset_party = false;
					break;
				default: std::cout<<"Invalid Command"<<std::endl;
					break;
				}
			}
		}
	} while (!game_over);
}
