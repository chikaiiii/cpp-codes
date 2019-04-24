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
	cout << "教授的月薪是：" << a.pay() << endl;
	cout << "副教授的月薪是：" << b.pay() << endl;
	cout << "讲师的月薪是：" << c.pay() << endl;
	cout << "管理人员的月薪是：" << d.pay() << endl;
	cout << "实验室人员的月薪是：" << e.pay() << endl;
	return 0;
}