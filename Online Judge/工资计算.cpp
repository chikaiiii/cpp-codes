#include<iostream>
using namespace std;
class Employee
{
public:
	Employee()
	{
		basicSalary = 2000;
		name[20] = '\0';
	}
	void print()
	{
		cout << "工资条：编号：" <<number<< "| ";
		cout << "姓名：" << name << endl;;
		cout << "| " << "工资：" <<pay() << endl;
	}
	void input()
	{
		cout << "请输入员工编号：" << endl;
		cin >> number;
		cout << "请输入员工名字：" << endl;
		cin >> name;
	}
	double pay()
	{
		return basicSalary;
	}
protected:
	int number;
	char name[20];
	double basicSalary;
};
class Salesman :public Employee
{
public:
	double pay()
	{
		return basicSalary + sales * commrate;
	}
	void input()
	{
		cout << "请输入销售额：" << endl;
		cin >> sales;
	}
	void print()
	{
		cout << "工资条：编号：" << number << "| ";
		cout << "姓名：" << name;
		cout << "| " << "工资：" << pay() << endl;
	}
	static double commrate;
protected:
	double sales;
};
class Salesmanager :public Employee, public Salesman
{
public:
	Salesmanager()
	{
		jobSalary = 3000;
	}
	double pay()
	{
		return Employee::basicSalary + sales * commrate + jobSalary;
	}
	void print()
	{
		cout << "工资条：编号：" << Employee::number << "| ";
		cout << "姓名：" << Employee::name;
		cout << "| " << "工资：" << pay() << endl;
	}
protected:
	double jobSalary;
};
double Salesman::commrate =0.005;
int main()
{
	int k;
	cout << "请选择员工职位：1、一般员工 2、销售员工 3、销售经理" << endl;
	cin >> k;
	switch (k)
	{
	case 1:
	{
		Employee a;
		a.input();
		a.pay();
		a.print();
		break;
	}
	case 2:
	{
		Salesman a;
		a.Employee::input();
		a.input();
		a.pay();
		a.print();
		break;
	}
	case 3:
	{
		Salesmanager a;
		a.Employee::input();
		a.Salesman::input();
		a.pay();
		a.print();
		break;
	}
	default: break;
	}
	system("pause");
	return 0;
}