/*********************************************************************
** Author: Jacob Souther
** Date: 05-Nov-2017
** Description: Implementation of the Die class. Allows for creation of die objects with a chosen amount of sides. The roll function returns a random integer between 1 and the number of sides.
*********************************************************************/

#include <iostream>

#include "die.hpp"

using std::cout;
using std::cin;

/*********************************************************************
** Description: Default constructor.
*********************************************************************/
Die::Die() 
{
	numSides = 6;
}

/*********************************************************************
** Description: Rolls the die. Returns an integer between 1 and the number of sides.
*********************************************************************/
int Die::rollDie()
{
	int num = rand() % numSides + 1;
	return num;
}

/*********************************************************************
** Description: Get the number of sides.
*********************************************************************/
int Die::getSides()
{
	return numSides;
}