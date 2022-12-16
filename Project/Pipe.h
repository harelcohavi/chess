#include "Chart.h"

class Pipe : public Chart
{
public:
	Pipe(Place location, bool color);
	~Pipe();
	
	bool canMove(Place dst) const override;
	bool move(Place dst) override;
};

