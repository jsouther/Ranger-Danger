/*********************************************************************
** Author: Jacob Souther
** Date: 05-Dec-2017
** Description: Implementation of the Player class.
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <algorithm>

#include "Player.hpp"
#include "getValidInt.hpp"

using std::cout;
using std::endl;

/*********************************************************************
** Description: Constructor.
*********************************************************************/
Player::Player()
{
	health = 100;
	food = 100;
	water = 100;
	bullets = 6;
}

/*********************************************************************
** Description: Set the player's location.
*********************************************************************/
void Player::setLocation(Space* location)
{
	this->location = location;
}

/*********************************************************************
** Description: Modify the player's health by an input amount.
*********************************************************************/
void Player::modifyHealth(int amount)
{
	health += amount;

	if (health > 100)
	{
		health = 100;
	}
}

/*********************************************************************
** Description: Modify the player's food by an input amount.
*********************************************************************/
void Player::modifyFood(int amount)
{
	food += amount;

	if (food > 100)
	{
		food = 100;
	}
}

/*********************************************************************
** Description: Modify the player's water by an input amount.
*********************************************************************/
void Player::modifyWater(int amount)
{
	water += amount;

	if (water > 100)
	{
		water = 100;
	}
}

/*********************************************************************
** Description: Modify the player's bullets by an input amount.
*********************************************************************/
void Player::modifyBullets(int amount)
{
	bullets += amount;

	if (bullets < 0)
	{
		bullets = 0;
	}
}

/*********************************************************************
** Description: Return the players health.
*********************************************************************/
int Player::getHealth()
{
	return health;
}

/*********************************************************************
** Description: Return the player's food.
*********************************************************************/
int Player::getFood()
{
	return food;
}

/*********************************************************************
** Description: Return the player's water.
*********************************************************************/
int Player::getWater()
{
	return water;
}

/*********************************************************************
** Description: Return the player's bullets.
*********************************************************************/
int Player::getBullets()
{
	return bullets;
}

/*********************************************************************
** Description: Return the player's current symbol.
*********************************************************************/
char Player::getSymbol()
{
	return symbol;
}

/*********************************************************************
** Description: Return the player's current location.
*********************************************************************/
Space* Player::getLocation()
{
	return location;
}

/*********************************************************************
** Description: Move the player along the map.
*********************************************************************/
void Player::movePlayer()
{	
	int choice;
	int steps = calculatePossibleSteps();

	// If the player is not at the ranger station
	if (location->getType() != 'S')
	{
		// If the player has enough resources to move
		if (steps > 0)
		{
			cout << "Would you like to:" << endl;
			cout << "1. Move away from the ranger station." << endl;
			cout << "2. Move towards the ranger station." << endl;
			cout << "3. Camp." << endl;

			choice = getValidInt(1, 3);
		}

		else
		{
			cout << "You do not have enough supplies to move. You must camp to gather supplies." << endl;
			choice = 3;
		}

		switch (choice)
		{
		
		// Move away from the ranger station
		case 1:
		{
			cout << endl << "How many steps would you like to take? (You have enough supplies to move " << steps << " steps)" << endl;

			int stepsAway = getValidInt(1, steps);

			// Move for as many steps as input
			for (int i = 0; i < stepsAway; i++)
			{
				// If the player is in the mountains
				if (location->getType() == 'M')
				{
					// If the player is not at the edge of the map
					if (location->getTop() != nullptr)
					{
						location = location->getTop();
						reduceSupplies();
					}

					// Stop moving at the edge of the map
					else
					{
						cout << "You cannot move forward any farther." << endl;
						break;
					}
				}
				
				// If the player is in the plains
				else if (location->getType() == 'P')
				{
					// If the player is not at the edge of the map
					if (location->getRight() != nullptr)
					{
						location = location->getRight();
						reduceSupplies();
					}

					// Stop moving at the edge of the map
					else
					{
						cout << "You cannot move forward any farther." << endl;
						break;
					}
				}

				// If the player is in the desert
				else if (location->getType() == 'D')
				{
					// if the player is not at the edge of the map
					if (location->getBottom() != nullptr)
					{
						location = location->getBottom();
						reduceSupplies();
					}

					// Stop moving at the edge of the map
					else
					{
						cout << "You cannot move forward any farther." << endl;
						break;
					}
				}

				// If the player is in the forest
				else if (location->getType() == 'F')
				{
					// If the player is not at the edge of the map
					if (location->getLeft() != nullptr)
					{
						location = location->getLeft();
						reduceSupplies();
					}

					// Stop moving at the edge of the map
					else
					{
						cout << "You cannot move forward any farther." << endl;
						break;
					}
				}
			}
			break;
		}

		// Move towards the ranger station
		case 2:
		{
			cout << endl << "How many steps would you like to take? (You have enough supplies to move " << steps << " steps)" << endl;

			int stepsToward = getValidInt(1, steps);

			// Move for the input amount of steps
			for (int i = 0; i < stepsToward; i++)
			{
				// If the player is in the mountains
				if (location->getType() == 'M')
				{
					location = location->getBottom();
					reduceSupplies();
				}

				// If the player is in the plains
				else if (location->getType() == 'P')
				{
					location = location->getLeft();
					reduceSupplies();
				}

				// If the player is in the desert
				else if (location->getType() == 'D')
				{
					location = location->getTop();
					reduceSupplies();
				}
				
				// If the player is in the forest
				else if (location->getType() == 'F')
				{
					location = location->getRight();
					reduceSupplies();
				}

				// If the player is at the ranger station
				else if (location->getType() == 'S')
				{
					cout << "You have arrived at the ranger station." << endl;
					break;
				}
			}
			break;
		}

		// Camp
		case 3:
		{
			camp();
			break;
		}
		}
	}
	
	// The player is at the ranger station.
	else
	{
		// If the player has enough supplies to leave the ranger station
		if (food >= 5 && water >= 5)
		{
			cout << "Would you like to:" << endl;
			cout << "1. Move 1 step away from the ranger station." << endl;
			cout << "2. Resupply." << endl;

			choice = getValidInt(1, 2);
		}

		// Otherwise, force the player to ressuply for a turn
		else
		{
			cout << "You do not have enough supplies to move. You must resupply at the ranger station for a turn." << endl;
			choice = 2;
		}

		switch (choice)
		{

		// Step away from the ranger station
		case 1:
		{
			cout << endl << "Where do you want to go?" << endl;
			cout << "1. Mountains." << endl;
			cout << "2. Plains." << endl;
			cout << "3. Desert." << endl;
			cout << "4. Forest." << endl;

			int direction = getValidInt(1, 4);

			reduceSupplies();

			switch (direction)
			{
			// Go to mountains
			case 1:
			{
				location = location->getTop();
				break;
			}

			// Go to plains
			case 2:
			{
				location = location->getRight();
				break;
			}

			// Go to desert
			case 3:
			{
				location = location->getBottom();
				break;
			}

			// Go to forest
			case 4:
			{
				location = location->getLeft();
				break;
			}
			}
			break;
		}

		// Ressuply
		case 2:
		{
			resupply();
			break;
		}
		}
	}

	cout << endl << "You now have " << food << " food, " << water << " water, " << bullets << " bullets, and " << health << " health." << endl;
}

/*********************************************************************
** Description: Calculate the max possible steps the player can take before running out of resources.
*********************************************************************/
int Player::calculatePossibleSteps()
{
	int steps = 0;
	int tempFood = food;
	int tempWater = water;

	// If the player is in the mountains
	if (location->getType() == 'M')
	{
		// Count the multiples of 15 food and 10 water in the player's inventory
		while (tempFood >= 15 && tempWater >= 10)
		{
			tempFood -= 15;
			tempWater -= 10;
			steps++;
		}
		
		// Count the multiples of 30 food the player has when they have insufficient water
		while (tempFood >= 30 && tempWater < 10)
		{
			tempFood -= 30;
			steps++;
		}

		// Count the multiples of 20 water the player has when they have insufficient food
		while (tempFood < 15 && tempWater >= 20)
		{
			tempWater -= 20;
			steps++;
		}

		return steps;
	}

	// If the player is in the plains
	if (location->getType() == 'P')
	{
		// Count the multiples of 5 food and 5 water in the player's inventory
		while (tempFood >= 5 && tempWater >= 5)
		{
			tempFood -= 5;
			tempWater -= 5;
			steps++;
		}

		// Count the multiples of 10 food the player has when they have insufficient water
		while (tempFood >= 10 && tempWater < 5)
		{
			tempFood -= 10;
			steps++;
		}

		// Count the multiples of 10 water the player has when they have insufficient food
		while (tempFood < 5 && tempWater >= 10)
		{
			tempWater -= 10;
			steps++;
		}

		return steps;
	}

	// If the player is in the desert
	if (location->getType() == 'D')
	{
		// Count the multiples of 5 food and 15 water in the player's inventory
		while (tempFood >= 5 && tempWater >= 15)
		{
			tempFood -= 5;
			tempWater -= 15;
			steps++;
		}

		// Count the multiples of 10 food the player has when they have insufficient water
		while (tempFood >= 10 && tempWater < 15)
		{
			tempFood -= 10;
			steps++;
		}
		
		// Count the multiples of 30 water the player has when they have insufficient food
		while (tempFood < 5 && tempWater >= 30)
		{
			tempWater -= 30;
			steps++;
		}

		return steps;
	}

	// If the player is in the forest
	if (location->getType() == 'F')
	{
		// Count the multiples of 10 food and 10 water in the player's inventory
		while (tempFood >= 10 && tempWater >= 10)
		{
			tempFood -= 10;
			tempWater -= 10;
			steps++;
		}

		// Count the multiples of 20 food the player has when they have insufficient water
		while (tempFood >= 20 && tempWater < 10)
		{
			tempFood -= 20;
			steps++;
		}

		// Count the multiples of 20 water the player has when they have insufficient food
		while (tempFood < 10 && tempWater >= 20)
		{
			tempWater -= 20;
			steps++;
		}

		return steps;
	}
}

/*********************************************************************
** Description: Reduce the players supplies.
*********************************************************************/
void Player::reduceSupplies()
{
	// If the player is in the mountains
	if (location->getType() == 'M')
	{
		// Reduce 15 food and 10 water
		if (food >= 15 && water >= 10)
		{
			food -= 15;
			water -= 10;
		}

		// If not enough food, reduce 20 water
		else if (food < 15 && water >= 20)
		{
			water -= 20;
		}

		// If not enough water, reduce 30 food
		else if (food >= 30 && water < 10)
		{
			food -= 30;
		}
	}

	// If the player is in the plains or at the ranger station
	if (location->getType() == 'P' || location->getType() == 'S')
	{
		// Reduce 5 food and 5 water
		if (food >= 5 && water >= 5)
		{
			food -= 5;
			water -= 5;
		}

		// If not enough food, reduce 10 water
		else if (food < 5 && water >= 10)
		{
			water -= 10;
		}

		// If not enough water, reduce 10 food
		else if (food >= 10 && water < 5)
		{
			food -= 10;
		}
	}

	// If the player is in the desert
	if (location->getType() == 'D')
	{
		// Reduce 5 food and 15 water
		if (food >= 5 && water >= 15)
		{
			food -= 5;
			water -= 15;
		}

		// If not enough food, reduce 30 water
		else if (food < 5 && water >= 30)
		{
			water -= 30;
		}

		// If not enough water, reduce 10 food
		else if (food >= 10 && water < 15)
		{
			food -= 10;
		}
	}

	// If the player is in the forest
	if (location->getType() == 'F')
	{
		// Reduce 10 food and 10 water
		if (food >= 10 && water >= 10)
		{
			food -= 10;
			water -= 10;
		}

		// If not enough food, reduce 20 water
		else if (food < 10 && water >= 20)
		{
			water -= 20;
		}

		// If not enough water, reduce 20 food
		else if (food >= 20 && water < 10)
		{
			food -= 20;
		}
	}
}

/*********************************************************************
** Description: Camp function. Give the player health and food or water.
*********************************************************************/
void Player::camp()
{
	if (health <= 80)
	{
		health += 20;
	}

	else
	{
		health = 100;
	}

	int choice;

	if (bullets > 0)
	{
		cout << endl << "You must choose to collect fresh water or hunt for food. (You also gain 20 health)" << endl;
		cout << "1. Gain 20 water." << endl;
		cout << "2. Gain 10 food (spend one bullet)." << endl;

		choice = getValidInt(1, 2);
	}

	else
	{
		cout << endl << "You have 0 bullets. You cannot hunt so you collect water instead." << endl;
		choice = 1;
	}
	switch (choice)
	{
	case 1:
	{
		if (water <= 80)
		{
			water += 20;
		}

		else
		{
			water = 100;
		}

		break;
	}
	case 2:
	{
		bool hunt = true;

		while (hunt)
		{
			if (food <= 90)
			{
				bullets--;
				food += 10;

				cout << endl << "You have " << food << " food and " << bullets << " bullets." << endl;
			}

			else
			{
				bullets--;
				food = 100;

				cout << endl << "You have " << food << " food and " << bullets << " bullets." << endl;
			}

			if (bullets > 0 && food < 100)
			{
				cout << endl << "Would you like to hunt again? (+10 food, -1 bullet)" << endl;
				cout << "1. Yes." << endl;
				cout << "2. No." << endl;

				int huntagain = getValidInt(1, 2);

				if (huntagain == 2)
				{
					hunt = false;
				}
			}

			else
			{
				hunt = false;
			}
		}
		
		break;
	}
	}

	cout << endl << "You have " << food << " food, " << water << " water and " << bullets << " bullets." << endl;
}

/*********************************************************************
** Description: Resupply at the ranger station to gain health and resources.
*********************************************************************/
void Player::resupply()
{
	bullets++;

	if (health <= 70)
	{
		health += 30;
	}

	else
	{
		health = 100;
	}

	if (food <= 75)
	{
		food += 25;
	}

	else
	{
		food = 100;
	}

	if (water <= 50)
	{
		water += 50;
	}

	else
	{
		water = 100;
	}
}