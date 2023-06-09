#ifndef QUEEN_H
#define QUEEN_H

#include "Bishop.h"
#include "Rook.h"

class Queen : public Chart
{
public:
	Queen(Place location, bool color);
	~Queen();

	bool canMove(Place dst) const override;

	static Queen* getQueen(int x, int y, bool color);
private:

};

#endif