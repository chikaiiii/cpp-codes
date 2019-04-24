#include<iostream>
using namespace std;
class Bank
{
	public:
	friend void total(Bank &a, Bank &b, Bank &c);
	Bank(double x)
	{
		balance=x;
	}
	private:
	double balance;
};
void total(Bank &a,Bank &b,Bank &c)
{
	double to=a.balance+b.balance+c.balance;
	cout<<to<<endl;
}
int main()
{
	double x,y,z;
	while(cin>>x>>y>>z)
	{
		Bank m(x);
		Bank n(y);
		Bank k(z);
		total(m,n,k);
	}
	return 0;
}