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
		cout << "请输入充值金额：" << endl;
		cin >> store;
		balance += store;
		income += balance;
	}
	void reduce()
	{
		double consume;
		cout << "请输入消费金额：" << endl;
		cin >> consume;
		balance -= consume;
		expenditure += consume;
		if (balance < 0) { cout << "余额不足" << endl; balance = 0; return; }
	}
	void print()
	{
		cout << "余额为：" << balance << "元" << endl;
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
		cout << "请输入会员姓名：" << endl;
		cin >> name;
		cout << "请输入会员密码：" << endl;
		cin >> password;
		cout << "请输入会员联系方式：" << endl;
		cin >> phonenumber;
	}
	void print()
	{
		cout << "编号：" << IDnumber << "|姓名："
			<< name << "|密码：" << password << "|联系方式：" << phonenumber 
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
		cout << "请输入会员密码：" << endl;
		cin >> pass;
		if (pass == password) {
			RMB::reduce();
			RMB::print();
		}
		else cout << "密码错误！" << endl;
	}
	void print(int t)
	{
		cout << "会员人数：" << t;
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
	if (f == NULL) cout << "无信息" << endl;
	else {
		memberCard *p=f;
		while (p->IDnumber != y)
		{
			p = p->next;
		}
		if (p == NULL) cout << "无信息" << endl;
		else p->chongzhi();
	}
}
void memberconsume(memberCard *&f, int z)
{
	if (f == NULL) cout << "无信息" << endl;
	else {
		memberCard *q = f;
		while (q->IDnumber != z)
		{
			q = q->next;
		}
		if (q == NULL) cout << "无信息" << endl;
		else q->xiaofei();
	}
}
void bianli(memberCard *&f,int m)
{
	if (m == 123456)
	{
		if (f == NULL) cout << "无信息" << endl;
		else {
			memberCard *pp = f;
			while (pp != NULL)
			{
				pp->Member::print();
				pp = pp->next;
			}
		}
	}
	else cout << "密码错误！" << endl;
}
int main()
{
	int k;
	int temp = 1;
	memberCard *front = NULL, *rear = NULL;
	cout << "1、新建会员|2、会员充值|3、会员消费|4、快捷店会员数、营业额|5、遍历会员列表|其他：退出" << endl;
	while (cin >> k) {
		switch (k)
		{
		case 1:buildmember(front, rear),total++; break;
		case 2: {int i; cout << "请输入会员ID编号：" << endl; cin >> i; memberstore(front, i);  break; }
		case 3:{int i; cout << "请输入会员ID编号：" << endl; cin >> i; memberconsume(front, i);  break; }
		case 4: {cout << "当前会员数：" << total; cout << "营业额：" << income - expenditure << "收入：" << income << "支出：" << expenditure << endl; break; }
		case 5: {int i; cout << "请输入查询密码：" << endl; cin >> i;  bianli(front, i); break;}
		default: {cout << "-----已退出-----" << endl; temp = 0; }
		}
		if (!temp) { break; }
		cout << "1、新建会员|2、会员充值|3、会员消费|4、快捷店会员数、营业额|5、遍历会员列表|其他：退出" << endl;
	}
	system("pause");
	return 0;
}