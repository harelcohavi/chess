#include "Board.h"
#include "Pipe.h"
#include "None.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"

<<<<<<< HEAD
#include <string>

#define COL 8	
=======
>>>>>>> 1bdbba3878f37f3d1fd421f612bbb9e5fc2597a1
#define WHITE true
#define BLACK false

Chart* Board::_board[64];

/*
	Ctor: 
	build the board
	Input: NONE
	Output: NONE
*/

Board::Board()
{
	int i = 0;
	int j = 0;
	None temp(Place(0, 0));

	for (i = 0; i < 8; i++)//set board to none
	{
		for (j = 0; j < 8; j++)
		{
			this->_board[(i * COL) + j] = None::getNone(i, j);
		}
	}

	this->_board[0 * COL + 0] = Rook::getRook(0, 0, BLACK);
	this->_board[7 * COL + 0] = Rook::getRook(7, 0, BLACK);
	this->_board[0 * COL + 7] = Rook::getRook(0, 7, WHITE);
	this->_board[7 * COL + 7] = Rook::getRook(7, 7, WHITE);
}

/*
	Dtor
	For now dont really needed, maybe will needed later
*/

Board::~Board()
{
}

/*
	return the board
	Input: NONE (there is only one board)
	Output: the board
*/

Chart** Board::getBoard()
{
	return _board;
}

/*
	This function turn the board into str
	Input: NONE 
	Output: string
*/

/*
- a b c d e f g h -
8 r # # # # # # r 8
7 # # # # # # # # 7
6 # # # # # # # # 6
5 # # # # # # # # 5
4 # # # # # # # # 4
3 # # # # # # # # 3
2 # # # # # # # # 2
1 R # # # # # # R 1
- a b c d e f g h -
*/
string Board::boardToStr()
{
	string str = "-\ta\tb\tc\td\te\tf\tg\th\t-\n";
	int i = 0;
	
	for (i = 0; i < 64; i++)
	{
		if (!((i) % 8))
		{
			int temp = 1+((i) / 8);
			str += to_string(temp) + "\t";
		}

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
			str += "\t";
		}
		else
		{
			str += "#";
		}

		if (!((i + 1) % 8))
		{
			int temp = ((i + 1) / 8);
			str += to_string(temp) + "\n";
		}
	}
	
	str += "-\ta\tb\tc\td\te\tf\tg\th\t-\n";
	return str;
}

/*
	check if there is check mate
	Input: NONE
	Output: true for check mate
*/

bool Board::checkMate()
{
	return false; //we maybe do it
}

/*
	check if there is check on the white king
	Input: NONE
	Output: true for check
*/

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

/*
	check if there is check on the black king
	Input: NONE
	Output: true for check
*/

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

/*
	try to move chart
	Input: NONE
	Output: the movement code
*/

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
	// a1a2 -> a,a=X / 1,2=Y
	srcType = Board::_board[src.getX()][src.getY()].getType();
	dstType = Board::_board[dst.getX()][dst.getY()].getType();
	
	//has no move: src and dst are the same
	if (src == dst)
	{
		return HAS_NO_MOVE;// are the same
	}

	//no chart: the src chart isnt the player chart
	//dst chart: the dst is the player chart

	if (playerColor) // white
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
	else // black
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