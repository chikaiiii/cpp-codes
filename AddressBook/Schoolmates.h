#pragma once
//Schoolmates.h

#include"Individual.h"

class Schoolmates :public Individual
{
public:
	//构造函数
	Schoolmates(string n, string g, string bir, string pn, string em, string sch):Individual(n,g,bir,pn,em)
	{
		school = sch;
	}
	~Schoolmates() {}

	//具体功能
	void print()
	{
		cout << name << "\t" << gender << "\t" << birthday << "\t" << phonenumber 
			<< "\t" << e_mail << "\t" << school << endl;
	}

private:
	string school;
};
