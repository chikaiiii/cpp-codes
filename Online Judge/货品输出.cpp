#include<iostream>
#include<string>
using namespace std;
class Goods
{
public:
	Goods(double x, int y, string p, string s)
	{
		price = x;
		num = y;
		product = p;
		sta = s;
	}
	double price;
	int num;
	string product;
	string sta;
	Goods* next;
};
void add(Goods*& f, Goods*& r, double x, int y, string p, string s)
{
	Goods* q = new Goods(x, y, p, s);
	if (f == NULL) f = r = q;
	else {
		r->next = q;
		r = r->next;
	}
}
int main()
{
	Goods* front = NULL;
	Goods* rear = NULL;
	double jiage;
	int shuliang,i=3;
	string chandi, yangshi;
	while (i--)
	{   
		cin >> jiage >> shuliang >> chandi >> yangshi;
		add(front, rear, jiage, shuliang, chandi, yangshi);
	}
	int n;
	cin >> n;
	switch (n)
	{
	case 1:
	{
		double south=0, north=0;
		Goods* ptr = front;
		while (ptr != NULL)
		{
			if ((ptr->product) == "南部") south += (ptr->price) * (ptr->num);
			if((ptr->product) == "北部") north += (ptr->price) * (ptr->num);
			ptr = ptr->next;
		}
		cout << south << endl << north << endl;
		
	}break;
	case 2:
	{
		double red=0, blue=0;
		Goods* ptr = front;
		while (ptr != NULL)
		{
			if ((ptr->sta) == "红色") red += (ptr->price) * (ptr->num);
			if ((ptr->sta) == "蓝色") blue += (ptr->price) * (ptr->num);
			ptr = ptr->next;
		}
		cout << red << endl << blue << endl;
		
	}break;
	case 3:
	{
		double pra=0, round=0;
		Goods* ptr = front;
		while (ptr != NULL)
		{
			if ((ptr->sta) == "平顶") pra += (ptr->price) * (ptr->num);
			if ((ptr->sta) == "圆顶") pra += (ptr->price) * (ptr->num);
			ptr = ptr->next;
		}
		cout <<pra<< endl << round << endl;
		
	}break;
	}
	return 0;
}