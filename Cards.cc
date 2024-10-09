#include "Cards.h"


#include <iostream>

#include <random>
#include <string>

Cards::Value Cards::IntToEnumValue(int value)
{
	switch (value)
	{

	case 1: return Value::kAce;
	case 2: return Value::k2;
	case 3: return Value::k3;
	case 4: return Value::k4;
	case 5: return Value::k5;
	case 6: return Value::k6;
	case 7: return Value::k7;
	case 8: return Value::k8;
	case 9: return Value::k9;
	case 10: return Value::k10;
	case 11: return Value::kJack;
	case 12: return Value::kQueen;
	case 13: return Value::kKing;

	}
	return{};
}

Cards::Cards(int value, int suit)
{
	value_ = static_cast<Value>(value);
	suit_ = static_cast<Suit>(suit);
}



std::string Cards::GetValueToString()
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
std::string Cards::GetSuitString()
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

int Cards::GetValueToInt()
{
	return static_cast<int>(value_);
}

bool Cards::operator>(std::vector<Cards>::const_reference other) const
{
	return value_ > other.value_;
}

bool Cards::CardCompare(const Cards& a, const Cards& b)
{
	return static_cast<int>(a.value_) < static_cast<int>(b.value_);
}
