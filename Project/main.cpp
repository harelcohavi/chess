#include "Board.h"
#include "Pipe.h"
#include "None.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"

int main()
{
	Board theBoard();
	Place src;
	Place dst;
	enum codes result = RIGHT;
	bool turn = true; //true for white turn, false for black turn
	string toDo = "";

	while (!Board::checkMate())
	{
		do
		{
			cin >> toDo;

			if (toDo.length() == 4)
			{
				src = Place(toDo[0] - 'a', toDo[1] - '0');
				dst = Place(toDo[2] - 'a', toDo[3] - '0');

				result = Board::move(src, dst, turn);

				cout << result;

			}

		} while (result >= 2 && result <= 7);

		turn = !turn;
	}

}