#include "Place.h"

/*
	Ctor:
	This function set a defult place
	Input: NONE
	Output: NONE
*/

Place::Place()
	:_x(0), _y(0)
{
}

/*
	Ctor:
	this funtion set point
	Input: x and y
	Output: NONE
*/

Place::Place(int x, int y)
	: _x(x), _y(y)
{
}

/*
	Dtor:
	No need
*/

Place::~Place()
{
}

/*
	Input: NONE
	Output: x
*/

int Place::getX()
{
	return this->_x;
}

/*
	Input: NONE
	Output: y
*/

int Place::getY()
{
	return this->_y;
}

/*
	This function change the place
	Input: the new place
	Output: NONE
*/

void Place::operator=(const Place other)
{
	this->_x = other._x;
	this->_y = other._y;
}