#include "Place.h"

enum ChartType
{
	BP,	//black pipe
	BB, //black bishop
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
	NN, //NONE
};

class Chart
{
public:
	Chart();
	Chart(enum ChartType chartType, Place location);
	~Chart();

	virtual bool canMove(Place dst) const = 0;
	virtual bool move(Place dst) = 0;
	enum ChartType getType() const;

protected:
	void changeType(enum ChartType chartType);

	enum ChartType _type;
	Place _location;
};