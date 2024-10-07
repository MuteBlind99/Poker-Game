#include "Carte.h"


#include <iostream>

#include <random>
#include <string>

Carte::Carte(int value, int suit)
{
	value_ = static_cast<Value>(value);
	suit_ = static_cast<Suit>(suit);
}



std::string Carte::GetValueToString()
{

	switch (value_)
	{
	case Value::kAce: return "Ace";
	case Value::k2: return "Two";
	case Value::k3: return "Three";
	case Value::k4: return "Four";
	case Value::k5: return "Five";
	case Value::k6: return "Six";
	case Value::k7: return "Seven";
	case Value::k8: return "Eight";
	case Value::k9: return "Nine";
	case Value::k10: return "Ten";
	case Value::kJack: return "Jack";
	case Value::kQueen: return "Queen";
	case Value::kKing: return "King";

	
	}
	return {};
	
}
std::string Carte::GetSuitString()
{
	switch (suit_)
	{
	case Suit::kSquare: return "Square";
	case Suit::kClub :return "Club";
	case Suit::kDiamond: return "Diamond";
	case Suit::kHeart: return "Heart";
	}
	return {};
}

int Carte::GetValueToInt()
{
	return static_cast<int>(value_);
}
