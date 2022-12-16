#include "Chart.h"

class None : public Chart
{
public:
	None(Place location);
	~None();

	bool canMove(Place dst) const override;
	bool move(Place dst) override;
};