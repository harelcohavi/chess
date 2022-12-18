#ifndef ROOK_H
#define ROOK_H

#include "Chart.h"

class Rook : public Chart
{
public:
	Rook(Place location, bool color);
	~Rook();

	bool canMove(Place dst) const override;

private:

};

#endif