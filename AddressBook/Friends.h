#pragma once
//Friends.h

#include"Individual.h"

class Friends :public Individual
{
public:
	//���캯��
	Friends(string n, string g, string bir, string pn, string em, string pla) :Individual(n, g, bir, pn, em)
	{
		place = pla;
	}
	~Friends() {}

	//���幦��
	void print()
	{
		cout << name << "\t" << gender << "\t" << birthday << "\t" << phonenumber
			<< "\t" << e_mail << "\t" << place << endl;
	}

private:
	string place;
};

