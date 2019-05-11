#pragma once
#ifndef _CLASS_H_
#define _CLASS_H_

#include<string>
#include"db_tm.h"

/*定义父类Contacts*/
class Contacts
{
public:
	Contacts(std::string Name,std::string Gender,std::string Birthday,std::string Phonenumber,std::string Emailaddress)
	{
		this->Name = Name;
		this->Gender = Gender;
		this->Birthday = Birthday;
		this->Phonenumber = Phonenumber;
		this->Emailaddress = Emailaddress;
	}	//构造联系人
	~Contacts();	//析构联系人
	virtual void Add();		//新增联系人
	/*virtual void Edit();	//编辑联系人（姓名和出生日期除外）
	virtual void DeleteContacts();	//删除联系人
	virtual void Print();	//打印全体人员的姓名、出生日期、电话和email地址
	void Sort();	//按照姓名或出生日期排序并打印
	void BirthdayFind();	//查找生日
	void ContactsFind();	//查找联系人
	void CountTheSameMonth();	//计算同一个月出生的人数*/
private:
	std::string Name, Gender, Birthday, Phonenumber, Emailaddress;
};
/*父类的函数*/
Contacts::~Contacts() {}
void Contacts::Add()
{
	db_tm test;
	test.connect_mysql();
	
	test.close_mysql();
}
/*定义子类Students*/
class Students:public Contacts
{
public:
	Students(std::string Name, std::string Gender, std::string Birthday, std::string Phonenumber, std::string Emailaddress,std::string school)
	:Contacts(Name, Gender, Birthday, Phonenumber, Emailaddress){
		this->school = school;
	}	//构造同学
	/*~Students();	//析构同学
	void Add();		//新增同学联系人
	void Edit();	//编辑同学联系人（姓名和出生日期除外）
	void DeleteContacts();	//删除同学联系人
	void Print();	//打印全体同学的姓名、出生日期、电话和email地址*/
private:
	std::string school;
};
/*定义子类Colleagues*/
class Colleagues :public Contacts
{
public:
	Colleagues(std::string Name, std::string Gender, std::string Birthday, std::string Phonenumber, std::string Emailaddress, std::string company)
		:Contacts(Name, Gender, Birthday, Phonenumber, Emailaddress) {
		this->company = company;
	}//构造同学
	/*~Colleagues();	//析构同事
	void Add();		//新增同事联系人
	void Edit();	//编辑同事联系人（姓名和出生日期除外）
	void DeleteContacts();	//删除同事联系人
	void Print();	//打印全体同事的姓名、出生日期、电话和email地址*/
private:
	std::string company;
};
/*定义子类Friends*/
class Friends :public Contacts
{
public:
	Friends(std::string Name, std::string Gender, std::string Birthday, std::string Phonenumber, std::string Emailaddress, std::string place)
		:Contacts(Name, Gender, Birthday, Phonenumber, Emailaddress) {
		this->place = place;
	}	//构造同学
	/*~Friends();		//析构朋友
	void Add();	//新增朋友联系人
	void Edit();	//编辑朋友联系人（姓名和出生日期除外）
	void DeleteContacts();	//删除朋友联系人
	void Print();	//打印全体朋友的姓名、出生日期、电话和email地址*/
private:
	std::string place;
};
/*定义子类Relatives*/
class Relatives :public Contacts
{
public:
	Relatives(std::string Name, std::string Gender, std::string Birthday, std::string Phonenumber, std::string Emailaddress, std::string call)
		:Contacts(Name, Gender, Birthday, Phonenumber, Emailaddress) {
		this->call= call;
	}	//构造亲戚
	/*~Relatives();	//析构亲戚
	void Add();		//新增亲戚联系人
	void Edit();	//编辑亲戚联系人（姓名和出生日期除外）
	void DeleteContacts();	//删除亲戚联系人
	void Print();	//打印全体亲戚的姓名、出生日期、电话和email地址*/
private:
	std::string call;
};
#endif
