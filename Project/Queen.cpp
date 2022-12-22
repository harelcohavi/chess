#include "Queen.h"
#include "Board.h"

/*
	Ctor:
	Input: location and color
	Output: NONE
*/

Queen::Queen(Place location, bool color)
	: Chart(WQ, location)
{
	if (!color)
	{
		this->changeType(BQ);
	}
}

/*
	Dtor:
	don't really nedded
*/

Queen::~Queen()
{
}

/*
	check if the queen can mov from one place to other
	i took the rook check and the bishop check bc that the way the queen moves
	Input: dst
	Output: true for can move
*/

bool Queen::canMove(Place dst) const
{
	int srcX = this->_location.getX();
	int srcY = this->_location.getY();
	int dstX = dst.getX();
	int dstY = dst.getY();
	int i = 0;
	Chart** board = Board::getBoard();
	Place dis = Place(dst.getX(), dst.getY()) - this->_location;
	Place temp = this->_location; //other ways i cant change him


	//rook move check
	if (srcX == dstX)
	{

		for (i = srcY; i < dstY; i)
		{
			if (board[i][srcX].getType() != NN)
			{
				return false; //have chart 
			}

			if (srcY > dstY)
			{
				i--;
			}
			else
			{
				i++;
			}
		}

		return true;
	}
	else if (srcY == dstY)
	{
		for (i = srcX; i < dstX; i)
		{
			if (board[srcY][i].getType() != NN)
			{
				return false; //have chart 
			}

			if (srcX > dstX)
			{
				i--;
			}
			else
			{
				i++;
			}
		}

		return true;
	}

	//bishop move check
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

Queen* Queen::getQueen(int x, int y, bool color)
{
	Queen* temp = new Queen(Place(x, y), color);

	return temp;
}