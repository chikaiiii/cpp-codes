#pragma once
//Relatives.h

#include"Individual.h"

class Relatives :public Individual
{
public:
	//构造函数
	Relatives(string n, string g, string bir, string pn, string em, string ca) :Individual(n, g, bir, pn, em)
	{
		call = ca;
	}
	~Relatives() {}

	//具体功能
	void print()
	{
		cout << name << "\t" << gender << "\t" << birthday << "\t" << phonenumber
			<< "\t" << e_mail << "\t" << call << endl;
	}

private:
	string call;
};


