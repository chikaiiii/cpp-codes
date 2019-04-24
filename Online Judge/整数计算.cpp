#include<iostream>
using namespace std;
class Integer
{
public:
	Integer(int a)
	{
		num = a;
	}
	friend void operator+(Integer &x,Integer &y);
	friend void operator-(Integer &x, Integer &y);
	friend void operator*(Integer &x, Integer &y);
	friend void operator/(Integer &x, Integer &y);
private:
	int num;
};
void operator+(Integer &x,Integer &y)
{
	int ans;
	ans=x.num + y.num;
	if (ans + 32768 < 0 || ans > 32767) { cout << "ERROR" << endl; return;}
	cout << ans << endl;
	return;
}
void operator-(Integer &x, Integer &y)
{
	int ans;
	ans = x.num - y.num;
	if (ans + 32768 < 0 || ans > 32767) { cout << "ERROR" << endl; return; }
	cout << ans << endl;
	return;
}
void operator*(Integer &x, Integer &y)
{
	int ans;
	ans = x.num * y.num;
	if (ans + 32768 < 0 || ans > 32767) { cout << "ERROR" << endl; return; }
	cout << ans << endl;
	return;
}
void operator/(Integer &x, Integer &y)
{
	int ans;
	ans = x.num / y.num;
	if (ans + 32768 < 0 || ans > 32767) { cout << "ERROR" << endl; return; }
	cout << ans << endl;
	return;
}
int main()
{
	int a, b;
	char op;
	cout << "���������Ҳ�������" << endl;
	while (cin >> a >> b)
	{
		Integer x(a), y(b);
		cout << "������������ţ�" << endl;
		cin >> op;
		switch (op)
		{
		case '+':x + y; break;
		case '-':x - y; break;
		case '*':x*y; break;
		case '/':x / y; break;
		}
		cout << "���������Ҳ�������" << endl;
	}
	system("pause");
	return 0;
}