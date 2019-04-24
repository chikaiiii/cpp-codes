#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	int r;
	while (cin >> n >> r)
	{
		double area = 0,t=360;
		double *angel = new double[n];
		for (int i = 0; i < n-1; i++)
		{
			cin >> *(angel + i);
			t -= *(angel + i);
		}
		for (int k = 0; k < n-1; k++)
		{
			area += r * r*sin((*(angel + k)/180)*3.1415926) / 2;
		}
		area += r * r*sin(t/180*3.1415926) / 2;
		cout << fixed << setprecision(2) << area << endl;
		delete []angel;
		angel = NULL;
	}
	return 0;
}