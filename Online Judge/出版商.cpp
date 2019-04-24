#include<iostream>
#include<string>
using namespace std;
class Publication
{
public:
	Publication()
	{
		price = 0;
	}
protected:
	string title;
	float price;
};
class Book :public Publication
{
public:
	Book(string x,float y,int z)
	{
		title = x;
		price = y;
		page = z;
	}
	void show()
	{
		cout << title << " " << price << " " << page << endl;
	}
private:
	int page;
};
class Tape :public Publication
{
public:
	Tape(string x,float y,float z)
	{
		title = x;
		price = y;
		playTime = z;
	}
	void show()
	{
		cout << title << " " << price << " " << playTime << endl;
	}
private:
	float playTime;
};
int main()
{
	string s1, s2;
	float n1, n2, n3;
	int m;
	cin >> s1 >> n1 >> m;
    cin >> s2 >> n2 >> n3;
	Book a(s1,n1,m);
	a.show();
	Tape b(s2, n2, n3);
	b.show();
	return 0;
}