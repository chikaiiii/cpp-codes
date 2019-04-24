#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct Point
{
	double x, y;
};
class Enermy
{
public:
	void setposition(Point a, int b)
	{
		pos.x = a.x;
		pos.y = a.y;
		L = b;
		sta = true;
	}
	void hurt()
	{
		if (L > 0) {
			L--; return;
		}
		else return;
	}
	bool dist(Point c)
	{
		double k = sqrt((c.x - pos.x) * (c.x - pos.x) + (c.y - pos.y) * (c.y - pos.y));
		if (k <= 10) return true;
		else return false;
	}
	bool judge()
	{
		if (L == 0) return true;
		else return false;
	}
	bool sta;
private:
	Point pos;
	int L;

};

int main()
{
	Enermy *arr=new Enermy[80];
	string s;
	Point p;
	int l;
	int key = 0;
	while (cin >> s)
	{
		switch (s[0])
		{
		case 'N':
		{
			cin >> p.x >> p.y >> l;
			arr[key].setposition(p, l);
			key++;break;
		}
		case 'B':
		{
			int killed = 0;
			cin >> p.x >> p.y;
			for (int i = 0; i < key; i++)
			{
				if (arr[i].dist(p))
				{
					arr[i].hurt();
				}
			}
			for (int j = 0; j < key; j++)
			{
				if (arr[j].sta && arr[j].judge()) {
					arr[j].sta = false;
					killed++;
				}
			}
			int survival = 0;
			for (int m = 0; m < key; m++)
			{

				if (arr[m].sta) survival++;
			}cout << killed << " " << survival << endl;;
			break;
		}
		}
		
	}
		delete[] arr;
		arr = NULL;
		return 0;
}