#include "Chart.h"

/*
	defualt ctor:
	Input: NONE
	Output: NONE
*/

Chart::Chart()
	:_type(NN), _location(Place(0,0))
{
}

/*
	Ctor:
	Input: type and location
	Output: NONE
*/

Chart::Chart(enum ChartType chartType, Place location)
	:_type(chartType), _location(location)
{
}

/*
	Dtor:
	dont really needed
*/

Chart::~Chart()
{
}

/*
	change the type, can use only if you inheritance from chart
	Input: the new type
	Output: NONE
*/

void Chart::changeType(enum ChartType chartType)
{
	this->_type = chartType;
}

/*
	move a chart
	Input: dst
	Output: noved or not
*/

void Chart::move(Place dst)
{
	this->_location = dst;
}

//Getters

/*
	Input: NONE
	Output: the location
*/

Place Chart::getLocation() const
{
	return this->_location;
}

/*
	Input: NONE
	Output: The type
*/

enum ChartType Chart::getType() const
{
	return this->_type;
}