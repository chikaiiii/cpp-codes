#include<iostream>
#include<cmath>
using namespace std;
const double PI = 3.1415926;
class Shape
{
public:
	virtual void print() = 0;
	virtual double area() = 0;
};
class TwoDimensional : public Shape
{
public:
	virtual double perimeter() = 0;
};
class ThreeDimensional :public Shape
{
public:
	virtual double volume() = 0;
};
class Circle :public TwoDimensional
{
public:
	Circle(double rx)
	{
		r = rx;
	}
	void print()
	{
		cout << r << endl;
	}
	double area()
	{
		return r * r*PI;
	}
	double perimeter()
	{
		return 2 * r*PI;
	}
private:
	double r;
};
class Cone : public ThreeDimensional
{
public:
	Cone(double rx, double hx)
	{
		r = rx;
		h = hx;
	}
	void print()
	{
		cout << r << "," << h << endl;
	}
	double area()
	{
		return r * r*PI + PI * r*sqrt(r*r + h * h);
	}
	double volume()
	{
		return PI * r*r*h / 3;
	}
private:
	double r,h;
};
class Triangle :public TwoDimensional
{
public:
	Triangle(double ax,double bx,double cx)
	{
		a = ax;
		b = bx;
		c = cx;
	}
	void print()
	{
		cout << a << "," << b << "," << c << endl;
	}
	double area()
	{
		double temp;
		temp = (a + b + c) / 2;
		return sqrt(temp*(temp - a)*(temp - b)*(temp - c));
	}
	double perimeter()
	{
		return a + b + c;
	}
private:
	double a, b, c;
};
class Rectangle : public TwoDimensional
{
public:
	Rectangle(double ax, double bx)
	{
		a = ax;
		b = bx;
	}
	void print()
	{
		cout << a << "," << b << endl;
	}
	double area()
	{
		return a * b;
	}
	double perimeter()
	{
		return 2 * (a + b);
	}
private:
	double a, b;
};
class Box :public ThreeDimensional
{
public:
	Box(double ax, double bx, double cx)
	{
		a = ax;
		b = bx;
		c = cx;
	}
	void print()
	{
		cout << a << "," << b << "," << c << endl;
	}
	double area()
	{
		return 2 * (a*b + a * c + b * c);
	}
	double volume()
	{
		return a * b*c;
	}
private:
	double a, b, c;
};
class Cylinder :public ThreeDimensional
{
public:
	Cylinder(double rx, double hx)
	{
		r = rx;
		h = hx;
	}
	void print()
	{
		cout << r << "," << h << endl;
	}
	double area()
	{
		return 2 * PI*r*r + 2 * PI*r*h;
	}
	double volume()
	{
		return PI * r*r*h;
	}
private:
	double r, h;
};
class Sphere :public ThreeDimensional
{
public:
	Sphere(double rx)
	{
		r = rx;
	}
	void print()
	{
		cout << r << endl;
	}
	double area()
	{
		return 4 * PI*r*r;
	}
	double volume()
	{
		return 4 * PI * r*r*r / 3;
	}
private:
	double r;
};
int main()
{
	Circle circle1(5); // °ë¾¶
	Cone cone1(5, 10); // µ×Ãæ°ë¾¶, ¸ß
	Triangle tri1(3, 4, 5); // ÈýÌõ±ß
	Rectangle rect1(6, 7); // ³¤, ¿í
	Box box1(3, 4, 5); // ³¤, ¿í, ¸ß
	Cylinder cy1(5, 10); // µ×Ãæ°ë¾¶, ¸ß
	Sphere sphere1(10); // Çò°ë¾¶
	circle1.print();
	cout << circle1.area() << endl << circle1.perimeter() << endl;
	cone1.print();
	cout << cone1.area() << endl << cone1.volume() << endl;
	tri1.print();
	cout << tri1.area() << endl << tri1.perimeter() << endl;
	rect1.print();
	cout << rect1.area() << endl << rect1.perimeter() << endl;
	box1.print();
	cout << box1.area() << endl << box1.volume() << endl;
	cy1.print();
	cout << cy1.area() << endl << cy1.volume() << endl;
	sphere1.print();
	cout << sphere1.area() << endl << sphere1.volume() << endl;
	return 0;
}