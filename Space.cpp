/*********************************************************************
** Author: Jacob Souther
** Date: 05-Dec-2017
** Description: Interface for the Space class.
*********************************************************************/

#include "Space.hpp"

/*********************************************************************
** Description: Constructor. Initializes the number of dice rolls the player gets when searching for lost hiker's in that space.
*********************************************************************/
Space::Space(int diceRolls)
{
	this->diceRolls = diceRolls;
}


/*********************************************************************
** Description: Return pointer to the space above this space.
*********************************************************************/
Space* Space::getTop()
{
	return top;
}

/*********************************************************************
** Description: Set the top pointer to the input space.
*********************************************************************/
void Space::setTop(Space* top)
{
	this->top = top;
}

/*********************************************************************
** Description: Return pointer to the space right of this space.
*********************************************************************/
Space* Space::getRight()
{
	return right;
}

/*********************************************************************
** Description: Set the right pointer to the input space.
*********************************************************************/
void Space::setRight(Space* right)
{
	this->right = right;
}

/*********************************************************************
** Description: Return pointer to the space left of this space.
*********************************************************************/
Space* Space::getLeft()
{
	return left;
}

/*********************************************************************
** Description: Set the left pointer to the input space.
*********************************************************************/
void Space::setLeft(Space* left)
{
	this->left = left;
}

/*********************************************************************
** Description: Return pointer to the space below this space.
*********************************************************************/
Space* Space::getBottom()
{
	return bottom;
}

/*********************************************************************
** Description: Set the bottom pointer to the input space.
*********************************************************************/
void Space::setBottom(Space* bottom)
{
	this->bottom = bottom;
}

/*********************************************************************
** Description: Return the space's location symbol.
*********************************************************************/
char Space::getSymbol()
{
	return symbol;
}

/*********************************************************************
** Description: Return the space's type.
*********************************************************************/
char Space::getType()
{
	return type;
}

/*********************************************************************
** Description: Return the number of dice rolls available in this space.
*********************************************************************/
int Space::getDiceRolls()
{
	return diceRolls;
}

/*********************************************************************
** Description: Destructor. Explicit definition required for pure virtual assignment.
*********************************************************************/
Space::~Space() {}