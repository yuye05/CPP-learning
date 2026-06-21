class Point
{
private:
	int x;
	int y;

public:
	Point():
		x(0), y(0){ }
	Point(int a, int b):
		x(a), y(b){ }

	//成员重载+，两种重载都写进去了
	//111 Point+Point类
	Point operator+(const Point& other) const
	{
		return Point(this->x + other.x, this->y + other.y);
	}

	//222 Point+int整数 类
	Point operator+(const int num) const
	{
		return Point(this->x + num, this->y + num);
	}

	//声明全局友元函数重载
	friend ostream& operator<<(ostream& os, const Point& a);
};

//输出流<<重载
ostream& operator<<(ostream& os, const Point& other)
{
	os << "(" << other.x << ", " << other.y << ")";
	return os;
}

int main()
{
	Point a(2, 5);
	Point b(2, 3);
	int num = 5;

	Point result1 = a + b;
	Point result2 = a + num;

	cout << result1 << endl;
	cout << result2 << endl;

	return 0;
}