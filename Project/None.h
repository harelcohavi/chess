#include "Chart.h"

class None : public Chart
{
public:
	None(Place location);
	~None();

	bool canMove(Place dst) override;
	void move(Place dst) override;

private:

};