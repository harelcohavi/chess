#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Chart.h"

using namespace std;

enum codes
{
	RIGHT = 0,
	CHECK,
	NO_CHART,
	DST_CHART,
	SELF_CHECK,
	ILLEGAL_INDEX,
	ILLEGAL_MOVE,
	HAS_NO_MOVE,
};

class Board
{
public:
	Board();
	~Board();
	enum codes move(Place src, Place dst, bool playerColor); //true for white
	
	static bool checkMate();

	static Chart** getBoard();
	static string boardToStr();

private:
	static Chart** _board;
	bool whiteCheck();
	bool blackCheck();

};

#endif // !BOARD_H