#include<iostream>
using namespace std;
class nauticamile_kilometer
{
private:
	double kilometer;
	double meter;
public:
	nauticamile_kilometer(double x)
	{
		meter = x;
	}
	nauticamile_kilometer(double x,int t)
	{
		kilometer = x;
	}
	void print()
	{
		cout << "千米数：" <<kilometer<< endl;
		cout << "米数：" << meter << endl;
	}
	operator double();
};
nauticamile_kilometer::operator double()
{
	return kilometer / 1.857;
}
int main()
{
	double d1,d2;
	cout << "初始化距离" << endl;
	cin >> d1>>d2;
	nauticamile_kilometer a(d1,1),b(d2);
	a.print();
	b.print();
	double(a);
	double(b);
	system("pause");
	return 0;
}