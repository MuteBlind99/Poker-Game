#include "Carte.h"


#include <iostream>

#include <random>

int Carte::DrawCard()

{
	
	std::random_device rd;
	std::uniform_int_distribution<int>symbol(0,13);
	carte_value = symbol(rd);
	return carte_value;

}
 int Carte::FieldCard()
{
	  
	 std::random_device rd;
	 std::uniform_int_distribution<int>symbol(0, 13);
	 carte_value = symbol(rd);
	 std::cout << carte_value<< '\n';
	 return carte_value;

}