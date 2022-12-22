#ifndef KING_H
#define KING_H

#include "Chart.h"

class King : public Chart
{
public:
	King(Place location, bool color);
	~King();

	bool canMove(Place dst) const override;

	static King* getKing(int x, int y, bool color);
};

#endif // !KING_H
