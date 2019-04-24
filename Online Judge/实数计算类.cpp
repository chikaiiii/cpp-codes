#include<iostream>
using namespace std;
class Real
{
public:
	Real(double a)
	{
		num = a;
	}
	friend void operator+(Real &x, Real &y);
	friend void operator-(Real &x, Real &y);
	friend void operator*(Real &x, Real &y);
	friend void operator/(Real &x, Real &y);
private:
	double num;
};
void operator+(Real &x, Real &y)
{
	double ans;
	ans = x.num + y.num;
	if (ans + 3.4e38 < 0 || ans > 3.4e38) { cout << "ERROR" << endl; return; }
	cout << ans << endl;
	return;
}
void operator-(Real &x, Real &y)
{
	int ans;
	ans = x.num - y.num;
	if (ans + 3.4e38 < 0 || ans > 3.4e38) { cout << "ERROR" << endl; return; }
	cout << ans << endl;
	return;
}
void operator*(Real &x, Real &y)
{
	int ans;
	ans = x.num * y.num;
	if (ans + 3.4e38 < 0 || ans > 3.4e38) { cout << "ERROR" << endl; return; }
	cout << ans << endl;
	return;
}
void operator/(Real &x, Real &y)
{
	int ans;
	ans = x.num / y.num;
	if (ans + 3.4e38 < 0 || ans > 3.4e38) { cout << "ERROR" << endl; return; }
	cout << ans << endl;
	return;
}
int main()
{
	double a, b;
	char op;
	cout << "ÇëÊäÈë×óÓÒ²Ù×÷Êý£º" << endl;
	while (cin >> a >> b)
	{
		Real x(a), y(b);
		cout << "ÇëÊäÈëÔËËã·ûºÅ£º" << endl;
		cin >> op;
		switch (op)
		{
		case '+':x + y; break;
		case '-':x - y; break;
		case '*':x*y; break;
		case '/':x / y; break;
		}
		cout << "ÇëÊäÈë×óÓÒ²Ù×÷Êý£º" << endl;
	}
	system("pause");
	return 0;
}