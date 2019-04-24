#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
double sum(double a,double b);
int main()
{
	double x, y;
	ifstream infile("d:\\D4T2.in");
	infile >> x >> y;
	cout <<std::fixed<< sum(x, y) << endl;
	return 0;
}
double sum(double a, double b)
{
	if (a == b) return 2 * (a + b);
	else {
		int key = 1;
		double total=0;
		while (key)
		{
			double t;
			if (fmod(a,b) == 0) {
				total += 4*b*(a/b); key = 0;
			}
			else {
				total += 4 * b * (a / b);
				t = a;
				a = b;
				b =fmod(t,b);
			}
		}
		return total;
	}
}