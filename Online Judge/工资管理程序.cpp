#include<iostream>
using namespace std;
class Employee
{
public:
	virtual void pay()= 0;
};
class Manager :public Employee
{
public:
	Manager()
	{
		salary=8000;
	}
	void pay()
	{
		cout << "1001 manager_zhang ��" << salary << endl;
	}
private:
	double salary;
};
class Saleman : public Employee
{
public:
	Saleman(double x)
	{
		salary = x * 0.1;
	}
	void pay()
	{
		cout << "2001 saleman_li ��" << salary << endl;
	}
private:
	double salary;
};
class ManagerSaleman :public Employee
{
public:
	ManagerSaleman(double x)
	{
		salary = 5000 + x * 0.02;
	}
	void pay()
	{
		cout << "3001 managerSaleman_wang ��" << salary << endl;
	}
private:
	double salary;
};
int main()
{
	double s;
	while(cin>>s)
	{
		Manager a;
		Saleman b(s);
		ManagerSaleman c(s);
		Employee *p;
		p = &a;
		p->pay();
		p = &b;
		p->pay();
		p = &c;
		p->pay();
	}
	return 0;
}