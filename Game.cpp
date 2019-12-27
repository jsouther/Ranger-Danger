/*********************************************************************
** Author: Jacob Souther
** Date: 05-Dec-2017
** Description: Implementation of the Game class.
*********************************************************************/

#include <iostream>

#include "Game.hpp"
#include "getValidInt.hpp"

using std::cout;
using std::endl;


/*********************************************************************
** Description: Initialize the game map.
*********************************************************************/
void Game::createMap()
{
	createMountains();
	createPlains();
	createDesert();
	createForest();
}

/*********************************************************************
** Description: Initialize the mountain portion of the map.
*********************************************************************/
void Game::createMountains()
{
	//Create the mountains
	for (int i = 0; i < REGION_SIZE; i++)
	{
		if (i < 3)
		{
			// The first 3 spaces have no dice roll when searching for lost
			mountains[i] = new Mountains(0);
		}

		else if (i >= 3 && i < 9)
		{
			// The next 6 spaces have one dice roll when searching for lost
			mountains[i] = new Mountains(1);
		}

		else if (i == 9)
		{
			// The final space has two dice rolls when searching for lost
			mountains[i] = new Mountains(2);
		}
	}
	
	//Assign the top and bottom pointers for mountain spaces
	for (int i = 0; i < REGION_SIZE; i++)
	{
		// Assign the first space to the ranger station and next mountain
		if (i == 0)
		{
			mountains[i]->setBottom(station);
			mountains[i]->setTop(mountains[i + 1]);
		}

		// Assign the middles spaces to the next and previous mountain
		if (i > 0 && i < REGION_SIZE - 1)
		{
			mountains[i]->setTop(mountains[i + 1]);
			mountains[i]->setBottom(mountains[i - 1]);
		}

		// Assign the last space only to the previous mountain
		else if (i == REGION_SIZE - 1)
		{
			mountains[i]->setBottom(mountains[i - 1]);
		}
	}

	// Assign the ranger station top pointer to the first mountain
	station->setTop(mountains[0]);
}

/*********************************************************************
** Description: Initialize the Plains portion of the map.
*********************************************************************/
void Game::createPlains()
{
	//Create the plains
	for (int i = 0; i < REGION_SIZE; i++)
	{
		if (i < 3)
		{
			plains[i] = new Plains(0);
		}

		else if (i >= 3 && i < 9)
		{
			plains[i] = new Plains(1);
		}

		else if (i == 9)
		{
			plains[i] = new Plains(2);
		}
	}

	//Assign the top and bottom pointers for plains spaces
	for (int i = 0; i < REGION_SIZE; i++)
	{
		// Assign the first space to the ranger station and next plain
		if (i == 0)
		{
			plains[i]->setLeft(station);
			plains[i]->setRight(plains[i + 1]);
		}

		// Assign the middle spaces to the next and previous plains
		if (i > 0 && i < REGION_SIZE - 1)
		{
			plains[i]->setRight(plains[i + 1]);
			plains[i]->setLeft(plains[i - 1]);
		}

		// Assign the last space only to the previous plains
		else if (i == REGION_SIZE - 1)
		{
			plains[i]->setLeft(plains[i - 1]);
		}
	}

	// Assign the ranger station right pointer to the first plains
	station->setRight(plains[0]);
}

/*********************************************************************
** Description: Initialize the Desert portion of the map.
*********************************************************************/
void Game::createDesert()
{
	//Create the deserts
	for (int i = 0; i < REGION_SIZE; i++)
	{
		if (i < 3)
		{
			desert[i] = new Desert(0);
		}

		else if (i >= 3 && i < 9)
		{
			desert[i] = new Desert(1);
		}

		else if (i == 9)
		{
			desert[i] = new Desert(2);
		}
	}

	//Assign the top and bottom pointers for desert spaces
	for (int i = 0; i < REGION_SIZE; i++)
	{
		// Assign the first space to the ranger station and next desert
		if (i == 0)
		{
			desert[i]->setTop(station);
			desert[i]->setBottom(desert[i + 1]);
		}

		// Assign the middle spaces to the next and previous deserts
		if (i > 0 && i < REGION_SIZE - 1)
		{
			desert[i]->setBottom(desert[i + 1]);
			desert[i]->setTop(desert[i - 1]);
		}

		// Assign the last space only to the previous desert
		else if (i == REGION_SIZE - 1)
		{
			desert[i]->setTop(desert[i - 1]);
		}
	}

	// Assign the ranger station right pointer to the first plains
	station->setBottom(desert[0]);
}

/*********************************************************************
** Description: Initialize the Forest portion of the map.
*********************************************************************/
void Game::createForest()
{
	//Create the mountains
	for (int i = 0; i < REGION_SIZE; i++)
	{
		if (i < 3)
		{
			forest[i] = new Forest(0);
		}

		else if (i >= 3 && i < 9)
		{
			forest[i] = new Forest(1);
		}

		else if (i == 9)
		{
			forest[i] = new Forest(2);
		}
	}

	//Assign the top and bottom pointers for forest spaces
	for (int i = 0; i < REGION_SIZE; i++)
	{
		// Assign the first space to the ranger station and next forest
		if (i == 0)
		{
			forest[i]->setRight(station);
			forest[i]->setLeft(forest[i + 1]);
		}

		// Assign the middle spaces to the next and previous forests
		if (i > 0 && i < REGION_SIZE - 1)
		{
			forest[i]->setLeft(forest[i + 1]);
			forest[i]->setRight(mountains[i - 1]);
		}

		// Assign the last space only to the previous forest
		else if (i == REGION_SIZE - 1)
		{
			forest[i]->setRight(mountains[i - 1]);
		}
	}

	// Assign the ranger station right pointer to the first plains
	station->setLeft(forest[0]);
}

/*********************************************************************
** Description: Randomly select the starting position for the player. Starts the player in the 2nd location of any region.
*********************************************************************/
void Game::setPlayerStartingLocation()
{
	int startingLocation = rand() % 4 + 1;

	switch (startingLocation)
	{
	case 1:
		player.setLocation(mountains[1]);
		break;
	case 2:
		player.setLocation(plains[1]);
		break;
	case 3:
		player.setLocation(desert[1]);
		break;
	case 4:
		player.setLocation(forest[1]);
		break;
	}
}

/*********************************************************************
** Description: Print the current state of the board.
** 'O' marks an empty space.
** 'R' marks the player.
** 'X' marks the ranger station.
*********************************************************************/
void Game::printBoard()
{
	cout << endl;

	Space* playerSpace = player.getLocation();

	//Print mountain region
	cout << "              Mountains" << endl << endl;

	for (int i = REGION_SIZE - 1; i >= 0; i--)
	{
		if (playerSpace != mountains[i])
		{
			cout << "                  " << mountains[i]->getSymbol() << endl;
		}

		else
		{
			cout << "                  " << player.getSymbol() << endl;
		}
	}

	//Print forest region
	cout << "Forests ";
	for (int i = REGION_SIZE - 1; i >= 0; i--)
	{
		if (playerSpace != forest[i])
		{
			cout << forest[i]->getSymbol();
		}

		else
		{
			cout << player.getSymbol();
		}
	}

	//Print ranger station
	if (playerSpace != station)
	{
		cout << station->getSymbol();
	}

	else
	{
		cout << player.getSymbol();
	}

	//Print plains region
	for (int i = 0; i < REGION_SIZE; i++)
	{
		if (playerSpace != plains[i])
		{
			cout << plains[i]->getSymbol();
		}

		else
		{
			cout << player.getSymbol();
		}
	}

	cout << " Plains" << endl;

	//Print desert region
	for (int i = 0; i < REGION_SIZE; i++)
	{
		if (playerSpace != desert[i])
		{
			cout << "                  " << desert[i]->getSymbol() << endl;
		}

		else
		{
			cout << "                  " << player.getSymbol() << endl;
		}
	}

	cout << endl << "                Desert" << endl << endl;
}

/*********************************************************************
** Description: Call the player move function.
*********************************************************************/
void Game::move()
{
	player.movePlayer();
}

/*********************************************************************
** Description: Reduce the health of each lost hiker by 5.
*********************************************************************/
void Game::reduceLostsHealth()
{
	// If the lost hiker has not already been saved. Reduce health by 5.
	if (!lostInMountainsSaved)
	{
		lostInMountains.loseHealth(3);
	}

	if (!lostInPlainsSaved)
	{
		lostInPlains.loseHealth(3);
	}

	if (!lostInDesertSaved)
	{
		lostInDesert.loseHealth(3);
	}

	if (!lostInForestSaved)
	{
		lostInForest.loseHealth(3);
	}
}

/*********************************************************************
** Description: Print the health of each lost hiker to the screen.
*********************************************************************/
void Game::displayLostsHealth()
{
	if (score < 4)
	{
		cout << endl << "Lost Hiker's Health" << endl;
		cout << "------------------" << endl;


		// Only print the lost hiker's health if they have not been returned to the ranger station
		if (!lostInMountainsSaved)
		{
			cout << "Mountains: " << lostInMountains.getHealth();

			if (!foundLostInMountains)
			{
				cout << endl;
			}

			else
			{
				cout << "*" << endl;
			}
		}

		if (!lostInPlainsSaved)
		{
			cout << "Plains: " << lostInPlains.getHealth();

			if (!foundLostInPlains)
			{
				cout << endl;
			}

			else
			{
				cout << "*" << endl;
			}
		}
	}

	if (!lostInDesertSaved)
	{
		cout << "Desert: " << lostInDesert.getHealth();

		if (!foundLostInDesert)
		{
			cout << endl;
		}

		else
		{
			cout << "*" << endl;
		}
	}

	if (!lostInForestSaved)
	{
		cout << "Forest: " << lostInForest.getHealth();

		if (!foundLostInForest)
		{
			cout << endl;
		}

		else
		{
			cout << "*" << endl;
		}
	}
}

/*********************************************************************
** Description: Roll dice each turn to attempt to find a lost hiker while in a region.
*********************************************************************/
void Game::searchForLost()
{
	int roll = 0;
	int numRolls = player.getLocation()->getDiceRolls();

	// For the number of allowed dice rolls of the player's current space
	for (int i = 0; i < numRolls; i++)
	{
		// Accumulate dice rolls
		roll += die.rollDie();
	}

	// If the player rolls a total higher than 4
	if (roll >= 5)
	{
		// If the player is in the mountains and has not already found the lost hiker in the mountains
		if (player.getLocation()->getType() == 'M' && !foundLostInMountains)
		{
			// Heal the hiker to full and mark them as found
			lostInMountains.setHealth(103);
			foundLostInMountains = true;
			cout << endl << "*********** You found the lost hiker in the Mountains! You nurse them back to health. Get them back to the ranger station! ***********" << endl;
		}

		// If the player is in the plains and has not found the lost hiker in the plains
		if (player.getLocation()->getType() == 'P' && !foundLostInPlains)
		{
			// Heal the hiker to full and mark them as found
			lostInPlains.setHealth(103);
			foundLostInPlains = true;
			cout << endl << "*********** You found the lost hiker in the Plains! You nurse them back to health. Get them back to the ranger station! ***********" << endl;
		}

		// If the player is in the desert and has not found the lost hiker in the desert
		if (player.getLocation()->getType() == 'D'  && !foundLostInDesert)
		{
			// Heal the hiker to full and mark them as found
			lostInDesert.setHealth(103);
			foundLostInDesert = true;
			cout << endl << "*********** You found the lost hiker in the Desert! You nurse them back to health. Get them back to the ranger station! ***********" << endl;
		}

		// If the player is in the forest and has not found the lost hiker in the forest
		if (player.getLocation()->getType() == 'F' && !foundLostInForest)
		{
			// Heal the hiker to full and mark them as found
			lostInForest.setHealth(103);
			foundLostInForest = true;
			cout << endl << "*********** You found the lost hiker in the Forest! You nurse them back to health. Get them back to the ranger station ***********" << endl;
		}
	}
}

/*********************************************************************
** Description: Give the player credit for returning a lost hiker to the ranger station.
*********************************************************************/
void Game::returnLostHiker()
{
	// If the player is at the ranger station
	if (player.getLocation()->getType() == 'S')
	{
		// If the lost hiker in the mountains has been found and not yet saved
		if (foundLostInMountains && !mountainsSaved)
		{
			// Add score and mark the hiker as saved
			score++;
			lostInMountainsSaved = true;
			mountainsSaved = true;
			cout << endl << "You saved the lost hiker in the Mountains!" << endl;
		}

		// If the lost hiker in the plains has been found and not yet saved
		if (foundLostInPlains && !plainsSaved)
		{
			// Add score and mark the hiker as saved
			score++;
			lostInPlainsSaved = true;
			plainsSaved = true;
			cout << endl << "You saved the lost hiker in the Plains!" << endl;
		}

		// If the lost hiker in the desert has been found and not yet saved
		if (foundLostInDesert && !desertSaved)
		{
			// Add score and mark the hiker as saved
			score++;
			lostInDesertSaved = true;
			desertSaved = true;
			cout << endl << "You saved the lost hiker in the Desert!" << endl;
		}

		// If the lost hiker in the forest has been found and not yet saved
		if (foundLostInForest && !forestSaved)
		{
			// Add score and mark the hiker as saved
			score++;
			lostInForestSaved = true;
			forestSaved = true;
			cout << endl << "You saved the lost hiker in the Forest!" << endl;
		}
	}
}

/*********************************************************************
** Description: Call random the random event functions.
*********************************************************************/
void Game::randomEvent()
{
	// If the player is in the mountains
	if (player.getLocation()->getType() == 'M')
	{
		randomEventMountains();
	}

	// If the player is in the plains
	if (player.getLocation()->getType() == 'P')
	{
		randomEventPlains();
	}

	// If the player is in the desert
	if (player.getLocation()->getType() == 'D')
	{
		randomEventDesert();
	}

	// If the player is in the forest
	if (player.getLocation()->getType() == 'F')
	{
		randomEventForest();
	}
}

/*********************************************************************
** Description: Random events that can occur in the mountains.
*********************************************************************/
void Game::randomEventMountains()
{
	int random = rand() % 5 + 1;

	switch (random)
	{

	// This event occurs 2/5 times
	case 1:
	case 2:
	{
		int choice;

		// If the player has enough resources let them choose
		if (player.getFood() >= 10 && player.getWater() >= 20)
		{
			cout << endl << "You encounter the abominable snowman! Do you?" << endl;
			cout << "1. Appease him with food and water. (lose 10 food and 20 water)" << endl;
			cout << "2. Fight him off. (lose 20 health)" << endl;

			choice = getValidInt(1, 2);
		}

		// Otherwise, they must lost health
		else
		{
			choice = 2;
		}

		if (choice == 1)
		{
			cout << endl << "You gave the abominable snowman 10 food and 20 water." << endl;

			player.modifyFood(-10);
			player.modifyWater(-20);
		}

		else
		{
			cout << endl << "The abominable snowman hits you on the head. (you lose 20 health)" << endl;
			player.modifyHealth(-20);
		}

		break;
	}
	
	case 3:
	{
		cout << endl << "The lost hiker succumbs to hypothermia. (they lose 40 health)" << endl;
		lostInMountains.loseHealth(40);
		break;
	}

	case 4:
	{
		cout << endl << "You stumble upon a river and stop to catch some fish. (you gain 30 food and 30 water)" << endl;
		player.modifyFood(30);
		player.modifyWater(30);
		break;
	}

	case 5:
	{
		cout << endl << "You found the lost hikers backpack. (you gain 5 food and 10 water)" << endl;
		player.modifyFood(5);
		player.modifyWater(10);
		break;
	}
	}

	cout << endl << "You have " << player.getFood() << " food, " << player.getWater() << " water, " << player.getBullets() << " bullets and " << player.getHealth() << " health." << endl;
}

/*********************************************************************
** Description: Random events that occur in the plains.
*********************************************************************/
void Game::randomEventPlains()
{
	int random = rand() % 5 + 1;

	switch (random)
	{
	case 1:
	{
		int choice;

		// If the player has enough resources, let them choose
		if (player.getFood() >= 10 && player.getWater() >= 20)
		{
			cout << endl << "You encounter a wild boar! Do you?" << endl;
			cout << "1. Appease him with food and water. (lose 10 food and 20 water)" << endl;
			cout << "2. Fight him off. (lose 20 health)" << endl;

			choice = getValidInt(1, 2);
		}

		// Otherwise, they must lose health
		else
		{
			choice = 2;
		}

		if (choice == 1)
		{
			cout << endl << "You gave the wild boar 10 food and 20 water." << endl;

			player.modifyFood(-10);
			player.modifyWater(-20);
		}

		else
		{
			cout << endl << "The wild boar gores your leg. (you lose 20 health)" << endl;
			player.modifyHealth(-20);
		}

		break;
	}

	// This event occurs 2/5 times
	case 2:
	case 3:
	{
		int choice;

		// If the player has enough resources, let them choose
		if (player.getBullets() >= 2)
		{
			cout << endl << "You are attacked by a tiger! Do you?" << endl;
			cout << "1. Shoot at the tiger. (lose 2 bullets, gain 10 food)." << endl;
			cout << "2. Fight it by hand. (lose 20 health)." << endl;

			choice = getValidInt(1, 2);
		}

		// Otherwise, they must lose health
		else
		{
			choice = 2;
		}

		if (choice == 1)
		{
			cout << endl << "You killed the tiger and harvested its meat. You lost 2 bullets and gained 10 food." << endl;

			player.modifyBullets(-2);
			player.modifyFood(10);
		}

		else
		{
			cout << endl << "You managed to fight off the tiger, but not without a scratch. You lose 20 health." << endl;
			player.modifyHealth(-20);
		}

		break;
	}

	case 4:
	{
		cout << endl << "You stumble upon a watering hole. You scavenge 5 food and 10 water." << endl;
		player.modifyFood(5);
		player.modifyWater(10);
		break;
	}

	case 5:
	{
		cout << endl << "The lost hiker begins to hallucinate and hurts himself in confusion. (They lose 20 health)" << endl;
		lostInPlains.loseHealth(20);
		break;
	}
	}

	cout << endl << "You have " << player.getFood() << " food, " << player.getWater() << " water, " << player.getBullets() << " bullets and " << player.getHealth() << " health." << endl;
}

/*********************************************************************
** Description: Random events that occur in the desert.
*********************************************************************/
void Game::randomEventDesert()
{
	int random = rand() % 5 + 1;

	switch (random)
	{
	case 1:
	{
		int choice;

		// If the player has enough resources, let them choose
		if (player.getFood() >= 10 && player.getWater() >= 20)
		{
			cout << endl << "You encounter a wandering desert ruffian! Do you?" << endl;
			cout << "1. Appease him with some supplies. (lose 10 food and 20 water)" << endl;
			cout << "2. Fight him off. (lose 20 health)" << endl;

			choice = getValidInt(1, 2);
		}

		// Otherwise, they must lose health
		else
		{
			choice = 2;
		}

		if (choice == 1)
		{
			cout << endl << "You gave the ruffian 10 food and 20 water." << endl;

			player.modifyFood(-10);
			player.modifyWater(-20);
		}

		else
		{
			cout << endl << "The ruffian vaguely insults your family. (you lose 20 health)" << endl;
			player.modifyHealth(-20);
		}

		break;
	}

	case 2:
	{
		int choice;

		// If the player has enough resources, let them choose
		if (player.getBullets() >= 1)
		{
			cout << endl << "You encounter a rabid camel. Do you?" << endl;
			cout << "1. Shoot the camel. (lose 1 bullet, gain 10 food)" << endl;
			cout << "2. Run from the camel. (lose 30 health)" << endl;

			choice = getValidInt(1, 2);
		}

		// Otherwise, they must lose health
		else
		{
			choice = 2;
		}

		if (choice == 1)
		{
			cout << endl << "You shoot the camel and collect its meat. You lose 1 bullet and gain 10 food." << endl;

			player.modifyBullets(-1);
			player.modifyFood(10);
		}

		else
		{
			cout << endl << "You try to run from the camel and trip! You are trampled. You lose 30 health." << endl;
			player.modifyHealth(-30);
		}

		break;
	}
	
	// This event occurrs 2/5 times
	case 3:
	case 4:
	{
		cout << endl << "You find an oasis! You scavenge 10 food and 20 water." << endl;
		player.modifyFood(10);
		player.modifyWater(20);
		break;
	}

	case 5:
	{
		cout << endl << "The lost hiker falls into a snake pit. They lose 40 health." << endl;
		lostInDesert.loseHealth(40);
		break;
	}
	}

	cout << endl << "You have " << player.getFood() << " food, " << player.getWater() << " water, " << player.getBullets() << " bullets and " << player.getHealth() << " health." << endl;
}

/*********************************************************************
** Description: Random events that occur in the forest
*********************************************************************/
void Game::randomEventForest()
{
	int random = rand() % 5 + 1;

	switch (random)
	{
	case 1:
	{
		int choice;

		// If the player has enough resource, let them choose
		if (player.getFood() >= 10 && player.getWater() >= 20)
		{
			cout << endl << "You approach a fork in the path! Do you?" << endl;
			cout << "1. Cross the river. (lose 10 food and 20 water)" << endl;
			cout << "2. Rappel the nearby cliffs. (lose 20 health)" << endl;

			choice = getValidInt(1, 2);
		}
		
		// Otherwise, they must lose health
		else
		{
			choice = 2;
		}

		if (choice == 1)
		{
			cout << endl << "You fall in the river and lose 10 food (and 20 water from exhaustion)." << endl;

			player.modifyFood(-10);
			player.modifyWater(-20);
		}

		else
		{
			cout << endl << "You rappel some nearby cliffs and slip. (you lose 20 health)" << endl;
			player.modifyHealth(-20);
		}

		break;
	}

	case 2:
	{
		int choice;

		// If the player has enough resources, let them choose
		if (player.getBullets() >= 2)
		{
			cout << endl << "You encounter a wild moose! Do you?" << endl;
			cout << "1. Shoot the moose. (lose 2 bullets)" << endl;
			cout << "2. Stand your ground. (lose 30 health)" << endl;

			choice = getValidInt(1, 2);
		}

		// Otherwise, they must lose health
		else
		{
			choice = 2;
		}

		if (choice == 1)
		{
			cout << endl << "You shoot the moose, but the body goes over a waterfall. You lose 2 bullets and are unable to retrieve the meat." << endl;

			player.modifyBullets(-2);
		}

		else
		{
			cout << endl << "A wild moose chases into a bear cave. The bear mauls you. You lose 30 health." << endl;
			player.modifyHealth(-30);
		}

		break;
	}

	// This event occurs 2/5 times
	case 3:
	case 4:
	{
		cout << endl << "You forage mushrooms by a stream. You gain 10 food and 20 water." << endl;
		player.modifyFood(10);
		player.modifyWater(20);
		break;
	}

	case 5:
	{
		cout << endl << "The lost hiker climbs a tree for a better view. They lose their grip and fall to the ground (losing 20 health)." << endl;
		lostInForest.loseHealth(20);
		break;
	}
	}

	cout << endl << "You have " << player.getFood() << " food, " << player.getWater() << " water, " << player.getBullets() << " bullets and " << player.getHealth() << " health." << endl;
}

/*********************************************************************
** Description: Check if the player should take damage at the end of a round and reduce health accordingly.
*********************************************************************/
void Game::damageCheck()
{
	if (player.getWater() == 0 && player.getFood() > 0)
	{
		cout << endl << "You have no water at the end of your turn. You lose 30 health." << endl;
		player.modifyHealth(-30);
	}

	if (player.getFood() == 0 && player.getWater() > 0)
	{
		cout << endl << "You have no food at the end of your turn. You lose 20 health." << endl;
		player.modifyHealth(-20);
	}

	if (player.getFood() == 0 && player.getWater() == 0)
	{
		cout << endl << "You have no food or water at the end of your turn. You lose 50 health." << endl;
		player.modifyHealth(-50);
	}
}

/*********************************************************************
** Description: Check if the game should be ended do to winning or losing.
*********************************************************************/
bool Game::gameOver()
{
	// If all four hikers have been rescued
	if (score == 4)
	{
		cout << endl << "You succesfully saved all of the lost hikers!" << endl;
		cout << "Congratulations, you win!" << endl;
		return true;
	}

	// If the player dies
	if (player.getHealth() <= 0)
	{
		cout << endl << "You died. Game Over." << endl;
		return true;
	}

	// If a hiker dies
	if (lostInMountains.getHealth() <= 0 || lostInPlains.getHealth() <= 0 || lostInDesert.getHealth() <= 0 || lostInForest.getHealth() <= 0)
	{
		cout << endl << "A lost hiker died. Game Over." << endl;
		return true;
	}

	return false;
}

/*********************************************************************
** Description: Free dynamically allocated memory.
*********************************************************************/
Game::~Game()
{
	delete station;

	for (int i = 0; i < REGION_SIZE; i++)
	{
		delete mountains[i];
		delete plains[i];
		delete desert[i];
		delete forest[i];
	}
}