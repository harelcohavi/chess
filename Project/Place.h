

class Place
{
public:
	Place();
	Place(int x, int y);
	~Place();

	int getX();
	int getY();
	void operator=(const Place other);

private:
	int _x;
	int _y;
};