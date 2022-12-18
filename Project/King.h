#ifndef KING_H
#define KING_H

#include "Chart.h"

class King : public Chart
{
public:
	King(Place location, bool color);
	~King();

	bool canMove(Place dst) const;
};

#endif // !KING_H
