#include "Knight.h"

/*
	Set the knight by color and location
	Input: color and location
	Output: NONE
*/

Knight::Knight(Place location, bool color)
	:Chart(WN, location)
{
	if (!color)
	{
		this->changeType(BN);
	}
}

/*
	Dtor:
	dont really needed
*/

Knight::~Knight()
{
}

/*
	check if the Knight can move to dst
	Input: dst
	Output: true for can move to dst
*/

bool Knight::canMove(Place dst) const
{
	if (this->_location == dst + Place(1, 2) || this->_location == dst + Place(1, -2))
	{
		return true;
	}
	if (this->_location == dst + Place(-1, 2) || this->_location == dst + Place(-1, -2))
	{
		return true;
	}
	if (this->_location == dst + Place(2, 1) || this->_location == dst + Place(2, -1))
	{
		return true;
	}
	if (this->_location == dst + Place(-2, 1) || this->_location == dst + Place(-2, -1))
	{
		return true;
	}

	return false;
}

/*
	create knight by x y and color
	Input: x, y and color
	Output: Pointer to a knight
*/

Knight* Knight::getKnight(int x, int y, bool color)
{
	Knight* temp = new Knight(Place(x, y), color);

	return temp;
}