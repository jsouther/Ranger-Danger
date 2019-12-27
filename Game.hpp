/*********************************************************************
** Author: Jacob Souther
** Date: 05-Dec-2017
** Description: Interface for the Game class.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "Space.hpp"
#include "Mountains.hpp"
#include "Plains.hpp"
#include "Desert.hpp"
#include "Forest.hpp"
#include "RangerStation.hpp"
#include "Player.hpp"
#include "LostHiker.hpp"
#include "die.hpp"

using std::vector;

class Game
{

private:
	static const int REGION_SIZE = 10;
	Mountains* mountains[REGION_SIZE];
	Plains* plains[REGION_SIZE];
	Desert* desert[REGION_SIZE];
	Forest* forest[REGION_SIZE];
	RangerStation* station = new RangerStation(0);
	Player player;
	LostHiker lostInMountains;
	bool foundLostInMountains = false;
	bool lostInMountainsSaved = false;
	LostHiker lostInPlains;
	bool foundLostInPlains = false;
	bool lostInPlainsSaved = false;
	LostHiker lostInDesert;
	bool foundLostInDesert = false;
	bool lostInDesertSaved = false;
	LostHiker lostInForest;
	bool foundLostInForest = false;
	bool lostInForestSaved = false;

	bool mountainsSaved = false;
	bool plainsSaved = false;
	bool desertSaved = false;
	bool forestSaved = false;

	Die die;
	int score = 0;
	
public:
	void createMap();
	void createMountains();
	void createPlains();
	void createDesert();
	void createForest();
	void setPlayerStartingLocation();
	void printBoard();
	void move();
	void reduceLostsHealth();
	void displayLostsHealth();
	void searchForLost();
	void returnLostHiker();
	void randomEvent();
	void randomEventMountains();
	void randomEventPlains();
	void randomEventDesert();
	void randomEventForest();
	void damageCheck();
	bool gameOver();
	~Game();
};

#endif // !GAME_HPP
