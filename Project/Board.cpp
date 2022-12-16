#include "Board.h"
#include "Pipe.h"
#include "None.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"


Board::Board()
{
	int i = 0;
	int j = 0;

	for (i = 2; i < 6; i++)
	{
		for (j = 0; j < 8; j++)
		{
			this->_board[i][j] = None(Place(i,j));
		}
	}
}

Board::~Board()
{
}

Chart** Board::getBoard()
{
	return _board;
}