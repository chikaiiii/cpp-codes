#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
class Circle
{
public:
	Circle(double x1, double y1, double r1)
	{
		x = x1;
		y = y1;
		r = r1;
	}
	friend void outputOverlap(Circle &a, Circle &b);
private:
	double x, y, r;
};
double min(double x, double y)
{
	if (x > y) return y;
	else return x;
}
void outputOverlap(Circle &a, Circle &b)
{
	double s=0, c=0;
	if (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)) >= (a.r + b.r)) cout << fixed << setprecision(4) << s << " " << c << endl;
	else if (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)) <= abs(a.r - b.r)) { s = 3.14159265*min(a.r, b.r)*min(a.r, b.r); c = 2 * 3.14159265*min(a.r, b.r); cout << fixed << setprecision(4) << s << " " << c << endl; }
	else {
		double m = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
		double n1 = (pow(a.r, 2) + pow(m, 2) - pow(b.r, 2)) / (2 * a.r*m);
		double n2 = (pow(b.r, 2) + pow(m, 2) - pow(a.r, 2)) / (2 * b.r*m);
		c = a.r * 2 * acos(n1) + b.r * 2 * acos(n2);
		s = a.r*a.r*acos(n1)-(a.r*a.r*sin(2*acos(n1))/2) + b.r*b.r*acos(n2)-(b.r*b.r*sin(2*acos(n2))/2);
		cout << fixed << setprecision(4) << s << " " << c<< endl;
	}
}
int main()
{
	int k;
	cin >> k;
	while (k--)
	{
		double x1, y1, r1;
		double x2, y2, r2;
		cin >> x1 >> y1 >> r1;
		cin >> x2 >> y2 >> r2;
		Circle round1(x1, y1, r1), round2(x2, y2, r2);
		outputOverlap(round1, round2);
	}
	return 0;
}