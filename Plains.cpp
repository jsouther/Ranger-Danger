/*********************************************************************
** Author: Jacob Souther
** Date: 05-Dec-2017
** Description: Implementation of the Plains class.
*********************************************************************/

#include "Plains.hpp"

/*********************************************************************
** Description: Constructor.
*********************************************************************/
Plains::Plains(int diceRolls) : Space(diceRolls) 
{
	symbol = 'O';
	type = 'P';
};