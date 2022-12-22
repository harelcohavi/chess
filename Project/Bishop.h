#ifndef BISHOP_H
#define BISHOP_H

#include "Chart.h"

class Bishop : public Chart
{
public:
	Bishop(Place location, bool color);
	~Bishop();

	bool canMove(Place dst) const override;

	static Bishop* getBishop(int x, int y, bool color);
private:

};
#endif