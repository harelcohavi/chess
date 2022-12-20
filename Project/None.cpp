#include "None.h"

None::None(Place location)
	: Chart(NN, location)
{
}

None::~None()
{
}

bool None::canMove(Place dst) const
{
	return false;
}

None& None::getNone(int y, int x)
{
	None temp = None(Place(y, x));

	return temp;
}