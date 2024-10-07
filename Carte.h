#ifndef CARTE_H
#define CARTE_H
#include <iostream>
#include <random>

class Carte
{
public:
	int carte_value = 0;
	int score;
	int suit;
	int field_card[3] = { 0 };
	int decksize = 3;
	int DrawCard();
	int FieldCard();
};
enum class Value
{
	kAce = 0,
	k2,
	k3,
	k4,
	k5,
	k6,
	k7,
	k8,
	k9,
	k10,
	kJack,
	kQueen,
	kKing,
};

enum class Suit
{
	kSquare,
	kClub,
	kHeart,
	kSpade

};

Value StringToValue(const std::string& card_value)
{
	Value real_value = StringToValue(card_value);
	switch (real_value)
	{
	case Value::kAce:
		std::cout << "Ace" << '\n';
		break;
	case Value::k2:
		std::cout << "Two" << '\n';
		break;
	case Value::k3:
		std::cout << "Tree" << '\n';
		break;
	case Value::k4:
		std::cout << "Four" << '\n';
		break;
	case Value::k5:
		std::cout << "Five" << '\n';
		break;
	case Value::k6:
		std::cout << "Six" << '\n';
		break;
	case Value::k7:
		std::cout << "Seven" << '\n';
		break;
	case Value::k8:
		std::cout << "Eight" << '\n';
		break;
	case Value::k9:
		std::cout << "Nine" << '\n';
		break;
	case Value::k10:
		std::cout << "Ten" << '\n';
		break;
	case Value::kJack:
		std::cout << "Jack" << '\n';
		break;
	case Value::kQueen:
		std::cout << "Queen" << '\n';
		break;
	case Value::kKing:
		std::cout << "King" << '\n';
		break;
	}
	return static_cast<Value>(0);
}

#endif // CARTE_H
