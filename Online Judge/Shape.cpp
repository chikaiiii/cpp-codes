#include<iostream>
#include<cmath>
using namespace std;
//定义Shape类...
class Shape
{
public:
	Shape()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	double x, y,z;
};
//定义二维图形类...
class TwoDimShape :public Shape
{
protected:
	double area,perimeter;
};
//定义三维图形类...
class ThreeDimShape :public Shape
{
protected:
	double surfacearea, volume;
};
//定义具体的派生类...
class Triangle : public TwoDimShape //定义三角形类...
{
public:
	void getposition(Shape p,Shape q,Shape r);
	double getarea();
	double getperimeter();
	void show2D();
private:
	Shape a, b, c;
};
class Circle :public TwoDimShape  //定义圆类...
{
public:
	void getposition(Shape x);
	void getround(double r);
	double getarea();
	double getperimeter();
	void show2D();
private:
	Shape mid;
	double rl;
};
class Rectangle :public TwoDimShape
{
public:
	void getposition(Shape p, Shape q);
	double getarea();
	double getperimeter();
	void show2D();
private:
	Shape a, b, c, d;
};
class Cone :public ThreeDimShape
{
public:
	void getposition(Shape p);
	void getparameter(double r, double h);
	double getsurfacearea();
	double getvolume();
	void show3D();
private:
	Shape mid;
	double rl, hl;
};
class Ball:public ThreeDimShape
{
public:
	void getposition(Shape p);
	void getround(double r);
	double getsurfacearea();
	double getvolume();
	void show3D();
private:
	Shape mid;
	double rl;
};
class Cuboid :public ThreeDimShape
{
public:
	void getposition(Shape p, Shape q);
	double getsurfacearea();
	double getvolume();
	void show3D();
private:
	Shape a, b;
};
//Triangle类成员函数...
void Triangle::getposition(Shape p, Shape q, Shape r)
{
	a.x = p.x;
	a.y = p.y;
	b.x = q.x;
	b.y = q.y;
	c.x = r.x;
	c.y = r.y;
}
double Triangle::getarea()
{
	double temp, temp1, temp2, temp3;
	temp1 = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	temp2 = sqrt(pow(c.x - b.x, 2) + pow(c.y - b.y, 2));
	temp3 = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));
	temp = (temp1 + temp2 + temp3) / 2;
	area=sqrt(temp*(temp - temp1)*(temp - temp2)*(temp - temp3));
	return area;
}
double Triangle::getperimeter()
{
	double temp1, temp2, temp3;
	temp1 = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	temp2 = sqrt(pow(c.x - b.x, 2) + pow(c.y - b.y, 2));
	temp3 = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));
	perimeter=temp1 + temp2 + temp3;
	return perimeter;
}
void Triangle::show2D()
{
	cout << "顶点坐标是" << "[" << a.x << "," << a.y << "]" << "[" << b.x << "," << b.y << "]"
		<< "[" << c.x << "," << c.y << "]" << endl;
	cout << "周长是" << getperimeter() << endl;
	cout << "面积是" << getarea() << endl;
}
//Circle类成员函数...
void Circle::getposition(Shape p)
{
	mid.x = p.x;
	mid.y = p.y;
}
void Circle::getround(double r)
{
	rl = r;
}
double Circle::getarea()
{
	area=3.14159265*rl*rl;
	return area;
}
double Circle::getperimeter()
{
	perimeter=3.14159265 * 2 * rl;
	return perimeter;
}
void Circle::show2D()
{
	cout << "圆心坐标是：" << "[" << mid.x << "," << mid.y << "]"<<endl;
	cout << "圆的半径是：" << rl << endl;
	cout << "圆的周长是：" << getperimeter() << endl;
	cout << "圆的面积是：" << getarea() << endl;
}
//Rectangle类成员函数...
void Rectangle::getposition(Shape p, Shape q)
{
	a.x = p.x;
	a.y = p.y;
	c.x = q.x;
	c.y = q.y;
}
double Rectangle::getarea()
{
	area=abs(a.x - c.x)*abs(a.y - c.y);
	return area;
}
double Rectangle::getperimeter()
{
	perimeter=abs(a.x - c.x) * 2 + abs(a.y - c.y) * 2;
	return perimeter;
}
void Rectangle::show2D()
{
	cout << "顶点坐标是" << "[" << a.x << "," << a.y << "]" << "[" << c.x << "," << a.y << "]"
		<< "[" << c.x << "," << c.y << "]" <<"["<<a.x<<","<<c.y<<"]"<< endl;
	cout << "周长是" << getperimeter() << endl;
	cout << "面积是" << getarea() << endl;
}
//Cone类成员函数...
void Cone::getposition(Shape p)
{
	mid.x = p.x;
	mid.y = p.y;
}
void Cone::getparameter(double r, double h)
{
	rl = r;
	hl = h;
}
double Cone::getsurfacearea()
{
	surfacearea = 3.14159265*rl*rl + 3.14159265*sqrt(rl*rl + hl * hl)*rl;
	return surfacearea;
}
double Cone::getvolume()
{
	volume = 3.14159265*rl*rl*hl / 3;
	return volume;
}
void Cone::show3D()
{
	cout << "底面圆心是：" << "[" << mid.x << "," << mid.y << "]" << endl;
	cout << "底面半径是：" << rl << endl;
	cout << "圆锥高是：" << hl << endl;
	cout << "圆锥表面积是：" << getsurfacearea() << endl;
	cout << "圆锥体积是：" << getvolume() << endl;
}
//Ball类成员函数...
void Ball::getposition(Shape p)
{
	mid.x = p.x;
	mid.y = p .y;
	mid.z = p.z;
}
void Ball::getround(double r)
{
	rl = r;
}
double Ball::getsurfacearea()
{
	surfacearea = 4 * 3.14159265*rl*rl;
	return surfacearea;
}
double Ball::getvolume()
{
	volume= 4 * 3.14159265*rl*rl*rl/3;
	return volume;
}
void Ball::show3D()
{
	cout << "球心是：" << "[" << mid.x << "," << mid.y <<","<<mid.z<< "]" << endl;
	cout << "球半径是：" << rl << endl;
	cout << "球表面积是：" << getsurfacearea() << endl;
	cout << "球体积是：" << getvolume() << endl;
}
//Cuboid类成员函数...
void Cuboid::getposition(Shape p,Shape q)
{
	a.x = p.x;
	a.y = p.y;
	a.z = p.z;
	b.x = q.x;
	b.y = q.y;
	b.z = q.z;
}
double Cuboid::getsurfacearea()
{
	surfacearea = (abs(a.x - b.x)*abs(a.y - b.y) + abs(a.x - b.x)*abs(a.z - b.z) + abs(a.z - b.z)*abs(a.y - b.y)) * 2;
	return surfacearea;
}
double Cuboid::getvolume()
{
	volume = abs(a.x - b.x)*abs(a.y - b.y)*abs(a.z - b.z);
	return volume;
}
void Cuboid::show3D()
{
	cout << "顶点坐标是" << "[" << a.x << "," << a.y <<","<<a.z<< "]" << "[" << b.x << "," << b.y << "," << a.z << "]"<< endl;
	cout << "长方体表面积是：" << getsurfacearea() << endl;
	cout << "长方体体积是：" << getvolume() << endl;
}
int main()
{
	Shape a1, b1, c1,d1;
	a1.x = 1;a1.y = 1;a1.z = 0;
	b1.x = 3;b1.y = 1;b1.z = 0;
	c1.x = 3;c1.y = 3;c1.z = 0;
	d1.x = 3;d1.y = 3;d1.z = 3;
	Triangle t1;
	t1.getposition(a1, b1, c1);
	t1.show2D();
	Circle t2;
	t2.getposition(a1);
	t2.getround(3);
	t2.show2D();
	Rectangle t3;
	t3.getposition(a1, c1);
	t3.show2D();
	Cone t4;
	t4.getposition(a1);
	t4.getparameter(3, 4);
	t4.show3D();
	Ball t5;
	t5.getposition(a1);
	t5.getround(3);
	t5.show3D();
	Cuboid t6;
	t6.getposition(a1, d1);
	t6.show3D();
	system("pause");
	return 0;
}
