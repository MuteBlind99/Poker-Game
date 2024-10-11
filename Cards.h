#ifndef CARTE_H
#define CARTE_H
#include <iostream>
#include <random>



class Cards
{
public:
	enum class Value
	{
		kNull = 0,
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
		kNoSuit,
	};

	static Value IntToEnumValue(int value);
	Value value_;
	Suit suit_;

	int score;
	int field_card[3] = { 0 };
	int decksize = 3;

	Cards(int value, int suit);
	Cards();

	std::string GetValueToString();
	std::string GetSuitString();
	int GetValueToInt();
	bool operator>(std::vector<Cards>::const_reference other) const;
	static bool CardCompare(const Cards& a, const Cards& b);
};


#endif // CARTE_H
