#include "Chart.h"

class None : public Chart
{
public:
	None();
	~None();

	bool canMove(Place dst) override;
	void move(Place dst) override;

private:

};