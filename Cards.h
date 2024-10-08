#ifndef CARTE_H
#define CARTE_H
#include <iostream>
#include <random>

enum class Suit;
enum class Value;

class Cards
{
public:
	Value value_;
	Suit suit_;
	
	int score;
	int field_card[3] = { 0 };
	int decksize = 3;

	Cards(int value, int suit);
	
	std::string GetValueToString();
	std::string GetSuitString();
	int GetValueToInt();
	static bool CardCompare(const Cards& a, const Cards& b);
};
enum class Value
{
	kAce = 1,
	k2 = 2,
	k3 = 3,
	k4 = 4,
	k5 = 5,
	k6 = 6,
	k7 = 7,
	k8 = 8,
	k9 = 9,
	k10 = 10,
	kJack = 11,
	kQueen = 12,
	kKing = 13,
};

enum class Suit
{
	kSquare,
	kClub,
	kHeart,
	kDiamond,

};



#endif // CARTE_H
