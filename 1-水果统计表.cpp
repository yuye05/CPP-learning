#include <string>
#include <iostream>
using namespace std;

class Fruit
{
private:
	string name;
	double price;
	static int count;
	static double total;

public:
	Fruit(string n, double p) :name(n), price(p) {
		count++;
		total += price;
	}
	
	static int Count()
	{
		return count;
	}
	static double Total()
	{
		return total;
	}

	void Print() const
	{
		cout << "这是" << name << "单价位" << price << endl;
	}
};

int Fruit::count = 0;
double Fruit::total = 0;

int main()
{
	Fruit f1("苹果", 6.6);
	Fruit f2("香蕉", 8.8);
	Fruit f3("芒果", 9.9);
	f1.Print();
	f2.Print();
	f3.Print();

	cout << "\n===== 统计如下 =====" << endl;
	cout << "总共有" << Fruit::Count()<< "种水果" << endl;
	cout << "一共" << Fruit::Total() << "元" << endl;
	return 0;
}
