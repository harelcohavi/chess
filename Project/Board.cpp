#include "Board.h"
#include "Pipe.h"
#include "None.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"

#define COL 8	
#define WHITE true
#define BLACK false

Chart* Board::_board[64];

Board::Board()
{
	int i = 0;
	int j = 0;
	None temp(Place(0, 0));

	for (i = 0; i < 8; i++)//set board to none
	{
		for (j = 0; j < 8; j++)
		{
			this->_board[(i * COL) + j] = &None::getNone(i, j);
		}
	}

	this->_board[0][0] = Rook::getRook(0, 0, BLACK);
	this->_board[0][7] = Rook::getRook(0, 7, BLACK);
	this->_board[7][0] = Rook::getRook(7, 0, WHITE);
	this->_board[7][7] = Rook::getRook(7, 7, WHITE);
}

Board::~Board()
{
}

Chart** Board::getBoard()
{
	return _board;
}

/*
	This function turn the board into str
	Input: NONE (the board by class)
	Output: string
*/

string Board::boardToStr()
{
	string str = "";
	int i = 0;

	for (i = 0; i < 64; i++)
	{
		if (_board[i])
		{
			switch (_board[i]->getType())
			{
			case BP:
				str += "p";
				break;
			case BB:
				str += "b";
				break;
			case BN:
				str += "n";
				break;
			case BR:
				str += "r";
				break;
			case BQ:
				str += "q";
				break;
			case BK:
				str += "k";
				break;
			case WP:
				str += "P";
				break;
			case WB:
				str += "B";
				break;
			case WN:
				str += "N";
				break;
			case WR:
				str += "R";
				break;
			case WQ:
				str += "Q";
				break;
			case WK:
				str += "K";
				break;
			default:
				str += "#";
				break;
			}
		}
		else
		{
			str += "#";
		}

		if (!((i + 1) % 8))
		{
			str += "\n";
		}
	}
	
	return str;
}

bool Board::checkMate()
{
	return false; //we maybe do it
}

bool Board::whiteCheck()
{
	King theKing(Place(0,0), WHITE);
	bool findKing = false;

	int i = 0;
	int j = 0;

	for (i = 0; i < 8 && !findKing; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (Board::_board[i][j].getType() == WK)
			{
				theKing.move(Place(i, j));
			}
		}
	}
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (Board::_board[i][j].getType() >= 1 && Board::_board[i][j].getType() <= 5) //everyone but the pipe
			{
				if (Board::_board[i][j].canMove(theKing.getLocation()))
				{
					return true;
				}
			}
			if (Board::_board[i][j].getType() == BP)//the black pipe
			{
				if (i + 1 == theKing.getLocation().getY() && (j + 1 == theKing.getLocation().getX() || j - 1 == theKing.getLocation().getX()))
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool Board::blackCheck()
{
	King theKing(Place(0, 0), BLACK);
	bool findKing = false;

	int i = 0;
	int j = 0;

	for (i = 0; i < 8 && !findKing; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (Board::_board[i][j].getType() == BK)
			{
				theKing.move(Place(i, j));
			}
		}
	}

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (Board::_board[i][j].getType() >= 7 && Board::_board[i][j].getType() <= 11) //everyone but the pipe
			{
				if (Board::_board[i][j].canMove(theKing.getLocation()))
				{
					return true;
				}
			}
			if (Board::_board[i][j].getType() == WP)//the white pipe
			{
				if (i - 1 == theKing.getLocation().getY() && (j + 1 == theKing.getLocation().getX() || j - 1 == theKing.getLocation().getX()))
				{
					return true;
				}
			}
		}
	}

	return false;
}

enum codes Board::move(Place src, Place dst, bool playerColor)
{
	enum ChartType srcType = NN;
	enum ChartType dstType = NN;
	Chart* killedChart = NULL;

	/**illegal index: the src or dst place is out of the board**/
	if (src.getX() > 7 || src.getY() > 7 || dst.getX() > 7 || dst.getY() > 7)
	{
		return ILLEGAL_INDEX;//too high
	}
	if (src.getX() < 0 || src.getY() < 0 || dst.getX() < 0 || dst.getY() < 0)
	{
		return ILLEGAL_INDEX;//too low
	}

	srcType = Board::_board[src.getY()][src.getX()].getType();
	dstType = Board::_board[dst.getY()][dst.getX()].getType();
	
	//has no move: src and dst are the same
	if (src == dst)
	{
		return HAS_NO_MOVE;// are the same
	}

	//no chart: the src chart isnt the player chart
	//dst chart: the dst is the player chart

	if (playerColor)
	{
		if (!(srcType >= 6 && srcType <= 11))
		{
			return NO_CHART; //its the white turn and the src is not white
		}
		if (dstType >= 6 && dstType <= 11)
		{
			return DST_CHART; //the dst is white
		}
	}
	else
	{
		if (!(srcType >= 0 && srcType <= 5))
		{
			return NO_CHART; //its the black turn and the src is not black
		}
		if (dstType >= 0 && dstType <= 5)
		{
			return DST_CHART; //the dst is black
		}
	}

	//illegal move: dont need to explain
	if (!(Board::_board[src.getY()][dst.getX()].canMove(dst)))
	{
		return ILLEGAL_MOVE;
	}

	//self check:
	killedChart = &_board[dst.getY()][dst.getX()];
	_board[dst.getY()][dst.getX()] = _board[src.getY()][src.getX()];
	
	if (playerColor)
	{
		if (whiteCheck())
		{
			_board[src.getY()][src.getX()] = _board[dst.getY()][dst.getX()];
			_board[dst.getY()][dst.getX()] = *killedChart;
			return SELF_CHECK;
		}
	}
	else
	{
		if (blackCheck())
		{
			_board[src.getY()][src.getX()] = _board[dst.getY()][dst.getX()];
			_board[dst.getY()][dst.getX()] = *killedChart;
			return SELF_CHECK;
		}
	}

	//now not need to return it back becouse its 100% legal move 

	//check: its legal move and its make check
	if (playerColor)
	{
		if (blackCheck())
		{
			return CHECK;
		}
	}
	else
	{
		if (whiteCheck())
		{
			return CHECK;
		}
	}

	return RIGHT;
}