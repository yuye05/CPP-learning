#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
	//虚函数
	virtual void Speak() = 0;
};

class Dog :public Animal
{
public:
	void Speak() override
	{
		cout << "狗：汪汪" << endl;
	}
};

class Cat :public Animal
{
public:
	void Speak() override
	{
		cout << "猫：喵喵" << endl;
	}
};
//统一接口！
void doSpeak(Animal& name)	//Animal是基类，用父类引用指向子类对象 → 实现多态
{
	name.Speak();
}

int main()
{
	Dog d1;
	Cat c1;
	//调用接口
	doSpeak(d1);
	doSpeak(c1);
	return 0;
}