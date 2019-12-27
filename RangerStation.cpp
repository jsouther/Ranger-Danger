/*********************************************************************
** Author: Jacob Souther
** Date: 05-Dec-2017
** Description: Implementation of the RangerStation class.
*********************************************************************/

#include "RangerStation.hpp"

/*********************************************************************
** Description: Constructor.
*********************************************************************/
RangerStation::RangerStation(int diceRolls) : Space(diceRolls) 
{
	symbol = 'X';
	type = 'S';
};