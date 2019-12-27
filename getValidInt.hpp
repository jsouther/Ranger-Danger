/*********************************************************************
** Author: Jacob Souther
** Date: 22-Oct-2017
** Description: Interface for the getValidInt function.
*********************************************************************/

// Include guard
#ifndef GETVALIDINT_HPP
#define GETVALIDINT_HPP

#include <limits>

int getValidInt(int min = std::numeric_limits<int>::min(), int max = std::numeric_limits<int>::max());

#endif // !GETVALIDINT_HPP