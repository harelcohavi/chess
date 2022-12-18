#include "King.h"
#include "Board.h"

King::King(Place location, bool color)
	: Chart(WK, location)
{
	if (!color)
	{
		changeType(BK);
	}
}
King::~King()
{
}

bool King::canMove(Place dst) const
{
	bool kingColor = this->getType() == WK;

	if ((dst.getX() == this->_location.getX() + 1 || dst.getX() == this->_location.getX() || dst.getX() == this->_location.getX() - 1) &&
		(dst.getY() == this->_location.getY() + 1 || dst.getY() == this->_location.getY() || dst.getY() == this->_location.getY() - 1))
	{
		if (kingColor)
		{
			if (!(Board::getBoard()[dst.getY()][dst.getX()].getType() >= 6 && Board::getBoard()[dst.getY()][dst.getX()].getType() <= 11))
			{
				return true;
			}
		}
		else
		{
			if (!(Board::getBoard()[dst.getY()][dst.getX()].getType() >= 0 && Board::getBoard()[dst.getY()][dst.getX()].getType() <= 5))
			{
				return true;
			}
		}
	}

	return false;
}