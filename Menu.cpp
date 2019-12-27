/*********************************************************************
** Author: Jacob Souther
** Date: 08-Oct-2017
** Description: Implementation of the menu function. Gets user input and returns a value based on that input.
*********************************************************************/

#include <iostream>
#include <string>

#include "getValidInt.hpp"
#include "Menu.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;

string menu(int counter)
{
	cout << endl << "Select an option (1-2):" << endl;
	if (counter == 0)
	{
		cout << "1. Play Ranger Danger." << endl;
	}
	
	if (counter > 0)
	{
		cout << "1. Play again." << endl;
	}

	cout << "2. Quit." << endl;

	// Prompt for input of the menu choice until an integer from 1 to the largest menu option is entered.
	int choice = getValidInt(1, 2);
	
	// Return the value of chosen menu input
	switch (choice)
	{
	case 1: 
		return "START";
	case 2: 
		cout << endl << "Program exited." << endl;
		return "QUIT";
	default:
		cout << "ERROR. Invalid menu option entered.";
		return "ERROR";
	}
}