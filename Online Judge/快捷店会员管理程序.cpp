#include<iostream>
using namespace std;
double income = 0;
double expenditure = 0;
int total = 0;
class RMB
{
public:
	RMB()
	{
		balance = 0;
	}
	void plus()
	{
		double store;
		cout << "�������ֵ��" << endl;
		cin >> store;
		balance += store;
		income += balance;
	}
	void reduce()
	{
		double consume;
		cout << "���������ѽ�" << endl;
		cin >> consume;
		balance -= consume;
		expenditure += consume;
		if (balance < 0) { cout << "����" << endl; balance = 0; return; }
	}
	void print()
	{
		cout << "���Ϊ��" << balance << "Ԫ" << endl;
	}
protected:
	double balance;
};
class Member
{
public:
	Member()
	{
		IDnumber = total;;
	}
	void input()
	{
		cout << "�������Ա������" << endl;
		cin >> name;
		cout << "�������Ա���룺" << endl;
		cin >> password;
		cout << "�������Ա��ϵ��ʽ��" << endl;
		cin >> phonenumber;
	}
	void print()
	{
		cout << "��ţ�" << IDnumber << "|������"
			<< name << "|���룺" << password << "|��ϵ��ʽ��" << phonenumber 
			<< endl;
	}
	int IDnumber;
protected:
	char name[20];
	int password;
	int phonenumber;
};
class memberCard :public Member, public RMB
{
public:
	memberCard()
	{
		Member();
		Member::input();
		RMB();
	}
	void chongzhi()
	{
		RMB::plus();
		RMB::print();
	}
	void xiaofei()
	{
		int pass;
		cout << "�������Ա���룺" << endl;
		cin >> pass;
		if (pass == password) {
			RMB::reduce();
			RMB::print();
		}
		else cout << "�������" << endl;
	}
	void print(int t)
	{
		cout << "��Ա������" << t;
	}
	memberCard *next;
};
void buildmember(memberCard *&f, memberCard *&r)
{
	memberCard *p = new memberCard;
	p->next = NULL;
	if (f == NULL)
	{
		f = r = p;
	}
	else
	{
		r->next = p;
		r = r->next;
	}
}
void memberstore(memberCard *&f, int y)
{
	if (f == NULL) cout << "����Ϣ" << endl;
	else {
		memberCard *p=f;
		while (p->IDnumber != y)
		{
			p = p->next;
		}
		if (p == NULL) cout << "����Ϣ" << endl;
		else p->chongzhi();
	}
}
void memberconsume(memberCard *&f, int z)
{
	if (f == NULL) cout << "����Ϣ" << endl;
	else {
		memberCard *q = f;
		while (q->IDnumber != z)
		{
			q = q->next;
		}
		if (q == NULL) cout << "����Ϣ" << endl;
		else q->xiaofei();
	}
}
void bianli(memberCard *&f,int m)
{
	if (m == 123456)
	{
		if (f == NULL) cout << "����Ϣ" << endl;
		else {
			memberCard *pp = f;
			while (pp != NULL)
			{
				pp->Member::print();
				pp = pp->next;
			}
		}
	}
	else cout << "�������" << endl;
}
int main()
{
	int k;
	int temp = 1;
	memberCard *front = NULL, *rear = NULL;
	cout << "1���½���Ա|2����Ա��ֵ|3����Ա����|4����ݵ��Ա����Ӫҵ��|5��������Ա�б�|�������˳�" << endl;
	while (cin >> k) {
		switch (k)
		{
		case 1:buildmember(front, rear),total++; break;
		case 2: {int i; cout << "�������ԱID��ţ�" << endl; cin >> i; memberstore(front, i);  break; }
		case 3:{int i; cout << "�������ԱID��ţ�" << endl; cin >> i; memberconsume(front, i);  break; }
		case 4: {cout << "��ǰ��Ա����" << total; cout << "Ӫҵ�" << income - expenditure << "���룺" << income << "֧����" << expenditure << endl; break; }
		case 5: {int i; cout << "�������ѯ���룺" << endl; cin >> i;  bianli(front, i); break;}
		default: {cout << "-----���˳�-----" << endl; temp = 0; }
		}
		if (!temp) { break; }
		cout << "1���½���Ա|2����Ա��ֵ|3����Ա����|4����ݵ��Ա����Ӫҵ��|5��������Ա�б�|�������˳�" << endl;
	}
	system("pause");
	return 0;
}