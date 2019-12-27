/*********************************************************************
** Author: Jacob Souther
** Date: 05-Dec-2017
** Description: Implementation of the Forest class.
*********************************************************************/

#include "Forest.hpp"


/*********************************************************************
** Description: Constructor.
*********************************************************************/
Forest::Forest(int diceRolls) : Space(diceRolls) 
{
	symbol = 'O';
	type = 'F';
};