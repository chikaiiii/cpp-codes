#include<iostream>
#define PI 3.14159265
using namespace std;
class Circle
{
public:
	virtual double area() = 0;
	virtual double volume() = 0;
protected:
	double radius;
};
class Sphere :public Circle
{
public:
	Sphere(double x)
	{
		radius = x;
	}
	double area()
	{
		return 4 * radius* radius* PI;
	}
	double volume()
	{
		return 4 * radius* radius* radius* PI / 3;
	}
};
class Column :public Circle
{
public:
	Column(double x, double y)
	{
		radius = x;
		height = y;
	}
	double area()
	{
		return 2 * radius* radius* PI + 2 * radius * PI * height;
	}
	double volume()
	{
		return radius * radius* PI* height;
	}
private:
	double height;
};
int main()
{
	Sphere a(3);
	Column b(3, 4);
	cout << "��ı�����ǣ�" << a.area() << " " << "�������ǣ�" << a.volume() << endl;
	cout << "Բ���ı�����ǣ�" << b.area() << " " << "Բ��������ǣ�" << b.volume() << endl;
	return 0;
}