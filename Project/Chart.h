#ifndef CHART_H
#define CHART_H

#include "Place.h"

enum ChartType
{
	BP = 0,	//black pipe
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
	void move(Place dst);

	enum ChartType getType() const;
	Place getLocation() const;

protected:
	void changeType(enum ChartType chartType);

	enum ChartType _type;
	Place _location;
};

#endif // !CHART_H