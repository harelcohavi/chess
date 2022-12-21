#include "None.h"

/*
	Ctor for a none chart place
	Input: location
	Output: NONE
*/

None::None(Place location)
	: Chart(NN, location)
{
}

/*
	Dtor:
	dont really needed
*/

None::~None()
{
}

/*
	allways false bc only charts can move
*/

bool None::canMove(Place dst) const
{
	return false;
}

/*
	doesnt work fine but should return a pointer to NONE chart
	Input: location
	Output: pointer to a None chart
*/

None* None::getNone(int y, int x)
{
	None temp = None(Place(y, x));

	return &temp;
}