#ifndef PLACE_H
#define PLACE_H

class Place
{
public:
	Place();
	Place(int x, int y);
	~Place();

	int getX() const;
	int getY() const;
	void operator=(const Place other);
	Place operator+(Place other) const;
	Place operator-(Place other) const;
	bool operator==(const Place other) const;

private:
	int _x;
	int _y;
};

#endif