#include "Chart.h"

Chart::Chart()
	:_type(NN), _location(Place(0,0))
{
}

Chart::Chart(enum ChartType chartType, Place location)
	:_type(chartType), _location(location)
{
}

Chart::~Chart()
{
}

void Chart::changeType(enum ChartType chartType)
{
	this->_type = chartType;
}

enum ChartType Chart::getType() const
{
	return this->_type;
}

bool Chart::move(Place dst)
{
	if (this->canMove(dst))
	{
		this->_location = dst;
		return true;
	}

	return false;
}

Place Chart::getLocation() const
{
	return this->_location;
}