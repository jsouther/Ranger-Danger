/*********************************************************************
** Author: Jacob Souther
** Date: 05-Dec-2017
** Description: Interface for the Player class.
*********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>

#include "Space.hpp"
#include "die.hpp"
#include "LostHiker.hpp"

using std::vector;

class Player
{
private:
	int health;
	int food;
	int water;
	int bullets;
	Space* location = nullptr;
	char symbol = 'R';
	
public:
	Player();
	void setLocation(Space*);
	void modifyHealth(int);
	void modifyFood(int);
	void modifyWater(int);
	void modifyBullets(int);
	int getHealth();
	int getFood();
	int getWater();
	int getBullets();
	Space* getLocation();
	char getSymbol();
	void movePlayer();
	int calculatePossibleSteps();
	void reduceSupplies();
	void camp();
	void resupply();
};

#endif // !PLAYER_HPP
