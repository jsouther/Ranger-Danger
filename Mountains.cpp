/*********************************************************************
** Author: Jacob Souther
** Date: 05-Dec-2017
** Description: Implementation of the Mountains class.
*********************************************************************/

#include "Mountains.hpp"


/*********************************************************************
** Description: Constructor.
*********************************************************************/
Mountains::Mountains(int diceRolls) : Space(diceRolls) 
{
	symbol = 'O';
	type = 'M';
};