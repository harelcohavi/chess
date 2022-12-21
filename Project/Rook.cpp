#include "Rook.h"
#include "Board.h"

/*
	Ctor:
	Input: location and color
	Output: NONE
*/

Rook::Rook(Place location, bool color)
	: Chart(WR, location)
{
	if (!color)
	{
		this->changeType(BR);
	}
}

/*
	Dtor:
	Dont really needed
*/

Rook::~Rook()
{
}

/*
	Check if he can move to the dst
	Input: the dst
	Output: true for can move false if cant move
*/


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

/*
	Input: x,y and color
	Output: pointer to a rook
*/

Rook* Rook::getRook(int y, int x, bool color)
{
	Rook temp(Place(y, x), color);

	return &temp;
}