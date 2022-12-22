#ifndef KNIGHT_H
#define KNIGHT_H

#include "Chart.h"

class Knight : public Chart
{
public:
	Knight(Place location, bool color);
	~Knight();

	bool canMove(Place dst) const override;

	static Knight* getKnight(int x, int y, bool color);
};

#endif