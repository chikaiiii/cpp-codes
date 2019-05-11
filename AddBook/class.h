#pragma once
#ifndef _CLASS_H_
#define _CLASS_H_

#include<string>
#include"db_tm.h"

/*���常��Contacts*/
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
	}	//������ϵ��
	~Contacts();	//������ϵ��
	virtual void Add();		//������ϵ��
	/*virtual void Edit();	//�༭��ϵ�ˣ������ͳ������ڳ��⣩
	virtual void DeleteContacts();	//ɾ����ϵ��
	virtual void Print();	//��ӡȫ����Ա���������������ڡ��绰��email��ַ
	void Sort();	//��������������������򲢴�ӡ
	void BirthdayFind();	//��������
	void ContactsFind();	//������ϵ��
	void CountTheSameMonth();	//����ͬһ���³���������*/
private:
	std::string Name, Gender, Birthday, Phonenumber, Emailaddress;
};
/*����ĺ���*/
Contacts::~Contacts() {}
void Contacts::Add()
{
	db_tm test;
	test.connect_mysql();
	
	test.close_mysql();
}
/*��������Students*/
class Students:public Contacts
{
public:
	Students(std::string Name, std::string Gender, std::string Birthday, std::string Phonenumber, std::string Emailaddress,std::string school)
	:Contacts(Name, Gender, Birthday, Phonenumber, Emailaddress){
		this->school = school;
	}	//����ͬѧ
	/*~Students();	//����ͬѧ
	void Add();		//����ͬѧ��ϵ��
	void Edit();	//�༭ͬѧ��ϵ�ˣ������ͳ������ڳ��⣩
	void DeleteContacts();	//ɾ��ͬѧ��ϵ��
	void Print();	//��ӡȫ��ͬѧ���������������ڡ��绰��email��ַ*/
private:
	std::string school;
};
/*��������Colleagues*/
class Colleagues :public Contacts
{
public:
	Colleagues(std::string Name, std::string Gender, std::string Birthday, std::string Phonenumber, std::string Emailaddress, std::string company)
		:Contacts(Name, Gender, Birthday, Phonenumber, Emailaddress) {
		this->company = company;
	}//����ͬѧ
	/*~Colleagues();	//����ͬ��
	void Add();		//����ͬ����ϵ��
	void Edit();	//�༭ͬ����ϵ�ˣ������ͳ������ڳ��⣩
	void DeleteContacts();	//ɾ��ͬ����ϵ��
	void Print();	//��ӡȫ��ͬ�µ��������������ڡ��绰��email��ַ*/
private:
	std::string company;
};
/*��������Friends*/
class Friends :public Contacts
{
public:
	Friends(std::string Name, std::string Gender, std::string Birthday, std::string Phonenumber, std::string Emailaddress, std::string place)
		:Contacts(Name, Gender, Birthday, Phonenumber, Emailaddress) {
		this->place = place;
	}	//����ͬѧ
	/*~Friends();		//��������
	void Add();	//����������ϵ��
	void Edit();	//�༭������ϵ�ˣ������ͳ������ڳ��⣩
	void DeleteContacts();	//ɾ��������ϵ��
	void Print();	//��ӡȫ�����ѵ��������������ڡ��绰��email��ַ*/
private:
	std::string place;
};
/*��������Relatives*/
class Relatives :public Contacts
{
public:
	Relatives(std::string Name, std::string Gender, std::string Birthday, std::string Phonenumber, std::string Emailaddress, std::string call)
		:Contacts(Name, Gender, Birthday, Phonenumber, Emailaddress) {
		this->call= call;
	}	//��������
	/*~Relatives();	//��������
	void Add();		//����������ϵ��
	void Edit();	//�༭������ϵ�ˣ������ͳ������ڳ��⣩
	void DeleteContacts();	//ɾ��������ϵ��
	void Print();	//��ӡȫ�����ݵ��������������ڡ��绰��email��ַ*/
private:
	std::string call;
};
#endif
