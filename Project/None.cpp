#include "None.h"

None::None(Place location)
	: Chart(NN, location)
{
}

None::~None()
{
}

bool None::canMove(Place dst)
{
	return false;
}

void None::move(Place dst)
{
}