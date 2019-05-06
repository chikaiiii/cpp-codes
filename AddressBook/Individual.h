#pragma once
//Individual.h

class Individual
{
public:
	//构造函数及析构函数
	Individual(string n,string g,string bir,string pn,string em)
	{
		name = n;
		gender = g;
		birthday= bir;
		phonenumber = pn;
		e_mail = em;
	}
	~Individual(){}

	void editphonenumber(string newpn)
	{
		phonenumber = newpn;
	}
	void edite_mail(string newem)
	{
		e_mail = newem;
	}

	//使用纯虚函数以便在不同的派生类中定义不同的实现
	virtual void print()const=0;
	virtual void editphonenumber()const=0;
	virtual void edite_mail()const = 0;

protected:
	string name;
	string gender;
	string birthday;
	string phonenumber;
	string e_mail;
};
