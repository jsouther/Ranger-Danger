/*********************************************************************
** Author: Jacob Souther
** Date: 05-Dec-2017
** Description: Implementation of the Desert class.
*********************************************************************/

#include "Desert.hpp"

/*********************************************************************
** Description: Constructor.
*********************************************************************/
Desert::Desert(int diceRolls) : Space(diceRolls) 
{
	symbol = 'O';
	type = 'D';
};