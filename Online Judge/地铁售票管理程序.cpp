#include<iostream>
using namespace std;
class CARD
{
public:
	virtual void print()= 0;
};
class OLDER :public CARD
{
public:
	OLDER(double dx,double px)
	{
		b = 100;
		dis = dx;
		pri = px;
	}
	void print()
	{
		if ((b - dis * pri) < 0) cout << "OLDER Please recharge!" << endl;
		else cout << "OLDER" << " " << dis * pri << endl;
		b -= dis * pri;
	}
private:
	double b, dis, pri;
};
class STUDENT :public CARD
{
public:
	STUDENT(double dx, double px)
	{
		b = 100;
		dis = dx;
		pri = px;
	}
	void print()
	{
		if ((b - dis * pri) < 0) cout << "STUDENT Please recharge!" << endl;
		else cout << "STUDENT" << " " << dis * pri << endl;
		b -= dis * pri;
	}
private:
	double b, dis, pri;
};
class COMMON :public CARD
{
public:
	COMMON(double dx, double px)
	{
		b = 100;
		dis = dx;
		pri = px;
	}
	void print()
	{
		if ((b - dis * pri) < 0) cout << "COMMON Please recharge!" << endl;
		else cout << "COMMON" << " " << dis * pri << endl;
		b -= dis * pri;
	}
private:
	double b, dis, pri;
};
int main()
{
	double o, s, c, p;
	int n;
	cin >> o >> s >> c >> p;
	cin >> n;
	OLDER A(o,p);
	STUDENT B(s,p);
	COMMON C(c,p);
	for (int i = 0; i < n; i++)
	{
		A.print();
		B.print();
		C.print();
	}
	return 0;
}