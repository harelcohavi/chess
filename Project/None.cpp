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

bool None::move(Place dst)
{
}