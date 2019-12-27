/*********************************************************************
** Author: Jacob Souther
** Date: 05-Dec-2017
** Description: Main function for Ranger Danger. Handles the start/quit functionality and the main gameplay loop.
*********************************************************************/

#include <string>
#include <ctime>
#include <iostream>

#include "Menu.hpp"
#include "Game.hpp"

using std::cout;
using std::endl;
using std::string;

int main()
{
	cout << "Welcome to Ranger Danger!" << endl << endl;
	cout << "You are a park ranger tasked with search and rescue of lost hikers. (Player denoted by 'R' on the map)" << endl;
	cout << "You must find and rescue the lost hikers in each region without dying or letting a hiker die." << endl;
	cout << "Your chances of a finding a lost hiker increase the farther away you get from the ranger station. (X on the map)" << endl << endl;
	cout << "Pay attention to your supplies: Health (max 100), Food (max 100), Water (max 100) and bullets." << endl;
	cout << "Each space that you move requires a certain amount of supplies depending on the region you are in." << endl;
	cout << "You can move as many spaces as you have sufficient supplies in a turn. (Each space denoted by 'O' on the map)" << endl;
	cout << "Camping allows you to recover health and choose to collect water or food (at the expense of bullets)." << endl << endl;
	cout << "Be careful, for the wild is full of unforseen dangers." << endl;
	cout << "Now go find those lost hikers and return them to the safety of the ranger station!" << endl;

	// Seed the random function
	srand(time(0));

	int counter = 0;

	while (true)
	{
		string menuChoice = menu(counter);

		if (menuChoice == "QUIT")
		{
			return 0;
		}

		if (menuChoice == "START")
		{
			
			Game game;

			game.createMap();
			game.setPlayerStartingLocation();
			game.displayLostsHealth();

			while (!game.gameOver())
			{
				std::cout << std::endl << "-------------------------------------------------------" << std::endl;

				game.printBoard();
				game.move();
				game.randomEvent();
				game.searchForLost();
				game.returnLostHiker();
				game.damageCheck();

				game.reduceLostsHealth();
				game.displayLostsHealth();
			}
		}

		counter++;
	}



	return 0;
}