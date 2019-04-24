#include<iostream>
using namespace std;
class Employee
{
public:
	virtual double pay() = 0;
	static double FundamentalSalary;
};
double Employee::FundamentalSalary = 3000;
class Teacher :public Employee
{
public:
	double ExtraSalary;
};
class Professor :public Teacher
{
public:
	Professor(double x)
	{
		ExtraSalary = 50;
		hours = x;
	}
	double pay()
	{
		return FundamentalSalary + ExtraSalary * hours;
	}
private:
	double hours;
};
class ViceProfessor :public Teacher
{
public:
	ViceProfessor(double x)
	{
		ExtraSalary = 30;
		hours = x;
	}
	double pay()
	{
		return FundamentalSalary + ExtraSalary * hours;
	}
private:
	double hours;
};
class Lecturer :public Teacher
{
public:
	Lecturer(double x)
	{
		ExtraSalary = 20;
		hours = x;
	}
	double pay()
	{
		return FundamentalSalary + ExtraSalary * hours;
	}
private:
	double hours;
};
class Manager :public Employee
{
public:
	Manager()
	{
		JobSalary = 2000;
	}
	double pay()
	{
		return FundamentalSalary + JobSalary;
	}
private:
	double JobSalary;
};
class Experiment :public Employee
{
public:
	Experiment(double x)
	{
		days = x;
		ExtraSalary = 20;
	}
	double pay()
	{
		return FundamentalSalary + ExtraSalary * days;
	}
private:
	int days;
	double ExtraSalary;
};
int main()
{
	Professor a(24);
	ViceProfessor b(24);
	Lecturer c(24);
	Manager d;
	Experiment e(28);
	cout << "���ڵ���н�ǣ�" << a.pay() << endl;
	cout << "�����ڵ���н�ǣ�" << b.pay() << endl;
	cout << "��ʦ����н�ǣ�" << c.pay() << endl;
	cout << "������Ա����н�ǣ�" << d.pay() << endl;
	cout << "ʵ������Ա����н�ǣ�" << e.pay() << endl;
	return 0;
}