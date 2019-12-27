/*********************************************************************
** Author: Jacob Souther
** Date: 05-Dec-2017
** Description: Interface for the LostHiker class.
*********************************************************************/

#ifndef LOSTHIKER_HPP
#define LOSTHIKER_HPP

class LostHiker
{
private:
	int health;
public:
	LostHiker();
	void loseHealth(int);
	void setHealth(int);
	int getHealth();
};

#endif // !LOSTHIKER_HPP