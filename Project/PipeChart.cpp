#include "PipeChart.h"
#include "Board.h"

/*
	Ctor:
	Input: location and color
	Output: NONE
*/

PipeChart::PipeChart(Place location, bool color)
	: Chart(WP, location)
{
	if (!color)
	{
		this->changeType(BP);
	}
}

/*
	Dtor:
	Dont really needed
*/

PipeChart::~PipeChart()
{
}

/*
	Check if he can move to the dst
	Input: the dst
	Output: true for can move false if cant move
*/

bool PipeChart::canMove(Place dst) const
{
	enum ChartType dstType = Board::getBoard()[dst.getY() * COL + dst.getX()]->getType();

	if (dstType == NN)
	{
		if ((this->_location - Place(0,1) == dst && this->_type == WP) || (this->_location + Place(0,1) == dst && this->_type == BP))
		{
			return true; //normal move
		}
		else if(this->_location.getY() == 1 || this->_location.getY() == 6) //may in the start position
		{
			if ((this->_location - Place(0,2) == dst && this->_type == WP) || (this->_location + Place(0,2) == dst && this->_type == BP))
			{
				return true;
			}
		}
	}

	if ((this->_location + Place(1, 1) == dst || this->_location + Place(-1, 1) == dst) && this->getType() == WP)
	{
		if(dstType >= 0 && dstType <= 5)
		{
			return true; //can eat them
		}
	}
	else if ((this->_location - Place(1, 1) == dst || this->_location - Place(-1, 1) == dst) && this->getType() == BP)
	{
		if (dstType >= 6 && dstType <= 11)
		{
			return true; //can eat them
		}
	}

	return false;
}

/*
	This function create Pipe
	Input: x,y and color
	Output: pointer to a pipe
*/

PipeChart* PipeChart::getPipe(int x, int y, bool color)
{
	return new PipeChart(Place(x, y), color);
}