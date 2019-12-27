/*********************************************************************
** Author: Jacob Souther
** Date: 05-Nov-2017
** Description: Interface for the Die class.
*********************************************************************/

// Include guard
#ifndef DIE_HPP
#define DIE_HPP

class Die
{
private:
	int numSides;

public:
	Die();
	int getSides();
	int rollDie();
};
#endif // !DIE_HPP
