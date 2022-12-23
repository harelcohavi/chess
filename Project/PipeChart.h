#ifndef PIPECHART_H
#define PIPECHART_H

#include "Chart.h"

class PipeChart : public Chart
{
public:
	PipeChart(Place location, bool color);
	~PipeChart();
	
	bool canMove(Place dst) const override;

	static PipeChart* getPipe(int x, int y, bool color);
private:

};

#endif