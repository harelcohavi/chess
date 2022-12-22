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

int Place::getX() const
{
	return this->_x;
}

/*
	Input: NONE
	Output: y
*/

int Place::getY() const
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

/*
	add the 2 places y
	Input: 2 places
	Output: the Place with the new y
*/

Place Place::operator+(Place other) const
{
	return Place(this->getX() + other.getX(), this->getY() + other.getY());
}

/*
	sub the firts place y from the second place 
*/

Place Place::operator-(Place other) const
{
	return Place(this->getX() - other.getX(), this->getY() - other.getY());
}

/*
	Check if 2 places are the same
*/

bool Place::operator==(const Place other) const
{
	return this->_x == other._x && this->_y == other._y;
}