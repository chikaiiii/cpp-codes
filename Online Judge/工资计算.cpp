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
		cout << "����������ţ�" <<number<< "| ";
		cout << "������" << name << endl;;
		cout << "| " << "���ʣ�" <<pay() << endl;
	}
	void input()
	{
		cout << "������Ա����ţ�" << endl;
		cin >> number;
		cout << "������Ա�����֣�" << endl;
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
		cout << "���������۶" << endl;
		cin >> sales;
	}
	void print()
	{
		cout << "����������ţ�" << number << "| ";
		cout << "������" << name;
		cout << "| " << "���ʣ�" << pay() << endl;
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
		cout << "����������ţ�" << Employee::number << "| ";
		cout << "������" << Employee::name;
		cout << "| " << "���ʣ�" << pay() << endl;
	}
protected:
	double jobSalary;
};
double Salesman::commrate =0.005;
int main()
{
	int k;
	cout << "��ѡ��Ա��ְλ��1��һ��Ա�� 2������Ա�� 3�����۾���" << endl;
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