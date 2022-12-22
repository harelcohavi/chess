#include "Bishop.h"
#include "Board.h"

/*
	Ctor:
	Build bishop by location and color
*/

Bishop::Bishop(Place location, bool color)
	: Chart(WB, location)
{
	if (!color)
	{
		this->changeType(BB);
	}
}

/*
	Dtor:
	Don't really needed
*/

Bishop::~Bishop()
{
}

/*
	check if the bishop can move to dst
	Input: dst
	Output: true for can move
*/

bool Bishop::canMove(Place dst) const
{
	Place dis = Place(dst.getX(), dst.getY()) - this->_location;
	Place temp = this->_location; //other ways i cant change him


	if (dis.getX() == dis.getY(), dis.getX() == -dis.getY())//he can do it, just need to check that there is no chart between them
	{
		if (this->_location.getX() > dst.getX())
		{
			if (this->_location.getY() > dst.getY())
			{
				while (!(temp == dst))
				{
					temp = temp - Place(1, 1);
					if (Board::getBoard()[temp.getX() * COL + temp.getY()]->getType() != NN)
					{
						return false;//there is chart between them
					}
				}
			}
			else
			{
				while (!(temp == dst))
				{
					temp = temp - Place(1, -1);
					if (Board::getBoard()[temp.getX() * COL + temp.getY()]->getType() != NN)
					{
						return false;//there is chart between them
					}
				}
			}
		}
		else
		{
			if (this->_location.getY() > dst.getY())
			{
				while (!(temp == dst))
				{
					temp = temp + Place(1, 1);
					if (Board::getBoard()[temp.getX() * COL + temp.getY()]->getType() != NN)
					{
						return false;//there is chart between them
					}
				}
			}
			else
			{
				while (!(temp == dst))
				{
					temp = temp + Place(1, -1);
					if (Board::getBoard()[temp.getX() * COL + temp.getY()]->getType() != NN)
					{
						return false;//there is chart between them
					}
				}
			}
		}

		return true;
	}

	return false;
}

/*
	Input: x,y and color 
	Output: pointer to a bishop
*/

Bishop* Bishop::getBishop(int x, int y, bool color)
{
	Bishop* temp = new Bishop(Place(x, y), color);

	return temp;
}