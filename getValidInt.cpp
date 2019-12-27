/*********************************************************************
** Author: Jacob Souther
** Date: 22-Oct-2017
** Description: The implementation of the getValidInt function. This function takes 2 optional parameters of min and max integer values used to constrain the input to a specific range of values. Returns the input if it is a valid integer. A valid integer is defined as any positive or negative integer which is within the optional constraints.
*********************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <limits>

#include "getValidInt.hpp"

using std::string;
using std::stringstream;
using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;

 int getValidInt(int min, int max)
{
	// Variables (in order of appearance)
	string input;
	int tempInt;
	char tempChar;
	bool valid = false;
	
	do
	{
		getline(cin, input);

		stringstream tempStream(input);

		// If input of stringstream into an int results in an error (not an int) or if input of stringstream into a char succeeds (there is an extra character after the integer) then valid remains false.
		//Credit to user 'Angew' at the following URL https://stackoverflow.com/questions/20287186/how-to-check-if-the-input-is-a-valid-integer-without-any-other-chars
		if (!(tempStream >> tempInt) || (tempStream >> tempChar) || input.empty())
		{
			cout << "Incorrect input: " << input << " is not an integer. Please enter an integer." << endl << endl;
		}

		else
		{
			valid = true;
		}

		// If the function is called with non default parameters for min and max
		if (valid && (min != std::numeric_limits<int>::min() || max != std::numeric_limits<int>::max()))
		{
			// Convert the valid user input into an integer
			int validInt = stoi(input);

			// If the input is outside the bounds of the min and max, valid returns to false 
			if (validInt < min || validInt > max)
			{
				cout << "Incorrect input: " << validInt << " is out of bounds. Please enter an integer from " << min << " to " << max << "." << endl << endl;
				valid = false;
			}
		}
	}
	while (!valid);

	// Return the valid input integer
	return stoi(input);
}
