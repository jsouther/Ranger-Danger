/*********************************************************************
** Author: Jacob Souther
** Date: 05-Dec-2017
** Description: Implementation of the LostHiker class.
*********************************************************************/

#include <iostream>

#include "LostHiker.hpp"

/*********************************************************************
** Description: Constructor. Initialize lost hiker's health between 70 and 100.
*********************************************************************/
LostHiker::LostHiker()
{
	health = rand() % 31 + 70;
}

/*********************************************************************
** Description: Reduce the hikers health by an input amount.
*********************************************************************/
void LostHiker::loseHealth(int amount)
{
	health -= amount;

	if (health < 0)
	{
		health = 0;
	}
}

/*********************************************************************
** Description: Set the hiker's health to a set amount.
*********************************************************************/
void LostHiker::setHealth(int health)
{
	this->health = health;
}

/*********************************************************************
** Description: Return a lost hiker's current health.
*********************************************************************/
int LostHiker::getHealth()
{
	return health;
}