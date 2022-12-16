#include "Place.h"

enum type
{
	BP,
	BB,
	BN,
	BR,
	BQ,
	BK,
	WP,
	WB,
	WN,
	WR,
	WQ,
	WK,
};

class Chart
{
public:
	Chart(enum type chartType, Place location);
	~Chart();

	virtual bool canMove(Place dst) = 0;
	virtual void move(Place dst) = 0;

private:
	enum type _type;
	Place _location;
};