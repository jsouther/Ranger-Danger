/*********************************************************************
** Author: Jacob Souther
** Date: 05-Dec-2017
** Description: Interface for the Space class. This is an abstract class.
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

class Space
{	
protected:
	char symbol;
	char type;

private:
	Space* top = nullptr;
	Space* right = nullptr;
	Space* left = nullptr;
	Space* bottom = nullptr;
	Space* head = nullptr;
	Space* tail = nullptr;
	int diceRolls;
	
public:
	Space(int);
	Space* getTop();
	void setTop(Space*);
	Space* getRight();
	void setRight(Space*);
	Space* getLeft();
	void setLeft(Space*);
	Space* getBottom();
	void setBottom(Space*);
	char getSymbol();
	char getType();
	int getDiceRolls();
	virtual ~Space() = 0;
};

#endif // !SPACE_HPP