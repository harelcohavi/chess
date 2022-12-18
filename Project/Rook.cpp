#include "Rook.h"
#include "Board.h"

Rook::Rook(Place location, bool color)
	: Chart(WP, location)
{
	if (!color)
	{
		this->changeType(BP);
	}
}

Rook::~Rook()
{
}

bool Rook::canMove(Place dst) const
{
	int srcX = this->_location.getX();
	int srcY = this->_location.getY();
	int dstX = dst.getX();
	int dstY = dst.getY();
	int i = 0;
	Chart** board = Board::getBoard();

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

	return false;
}
