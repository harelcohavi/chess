#include "Chart.h"

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
	bool whiteCheck();
	bool blackCheck();
	static Chart** getBoard();

private:
	static Chart** _board;

};

