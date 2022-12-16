#include "Pipe.h"
#include "Board.h"

Pipe::Pipe(Place location, bool color)
	: Chart(WP, location)
{
	if (!color)
	{
		this->changeType(BP);
	}
}

Pipe::~Pipe()
{
}

bool Pipe::canMove(Place dst) const 
{
	enum ChartType dstType = Board::getBoard()[dst.getX()][dst.getY()].getType();

	if (dstType == NN)
	{
		if ((this->_location + 1 == dst && this->_type == WP) || (this->_location - 1 == dst && this->_type == BP))
		{
			return true; //normal move
		}
		else if(this->_location.getY() == 1 || this->_location.getY() == 6) //may in the start position
		{
			if ((this->_location + 2 == dst && this->_type == WP) || (this->_location - 2 == dst && this->_type == BP))
			{
				return true;
			}
		}
	}

	if (((Place(this->_location.getX() + 1, this->_location.getY() + 1) == dst || Place(this->_location.getX() - 1, this->_location.getY() + 1) == dst) && this->getType() == WP) ||
		((Place(this->_location.getX() + 1, this->_location.getY() - 1) == dst || Place(this->_location.getX() - 1, this->_location.getY() - 1) == dst) && this->getType() == BP))
	{
		if(dstType == BB || dstType == BK || dstType == BN || dstType == BP || dstType == BQ || dstType == BR)
		{
			return true; //can eat them
		}
	}

	return false;
}

/*
	move the chart
	Input: dst
	Output: true for moved
*/

bool Pipe::move(Place dst)
{
	if (this->canMove(dst))//just a double check, but this function shold not call if it cant move
	{
		this->_location = dst;
		return true;
	}

	return false;
}