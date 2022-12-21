#ifndef NONE_H
#define NONE_H

#include "Chart.h"

class None : public Chart
{
public:
	None(Place location);
	~None();

	bool canMove(Place dst) const override;

	static None* getNone(int y, int x);
};

#endif