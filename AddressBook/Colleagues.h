#pragma once
//Colleagues.h

#include"Individual.h"

class Colleagues :public Individual
{
public:
	//构造函数
	Colleagues(string n, string g, string bir, string pn, string em, string com) :Individual(n, g, bir, pn, em)
	{
		company = com;
	}
	~Colleagues() {}

	//具体功能
	void print()
	{
		cout << name << "\t" << gender << "\t" << birthday << "\t" << phonenumber
			<< "\t" << e_mail << "\t" << company << endl;
	}
	
private:
	string company;
};
