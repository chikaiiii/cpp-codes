#include<iostream>
#include<cstring>
using namespace std;
class Mystring
{
public:
	Mystring()
	{
		asciisum = 0;
	}
	void getstr()
	{
		cin >> str;
	}
	void getsum()
	{
		int len = strlen(str);
		for (int i = 0; i < len; i++)
		{
			asciisum += str[i];
		}
	}
	void print()
	{
		cout << str<<" "; 
	}
    bool operator>(Mystring &B);
	Mystring & operator=(Mystring &A);
private:
	char str[20];
	int asciisum;
};
bool Mystring::operator>(Mystring &B)
{
	if (asciisum > B.asciisum) return true;
	else return false;
}
Mystring & Mystring::operator=(Mystring &A)
{
	strcpy(str, A.str);
	asciisum = A.asciisum;
	return *this;
}
int main()
{
	int k;
	cin >> k;
	for (int a = 0; a < k; a++)
	{
		int m;
		cin >> m;
		Mystring *p = new Mystring[m];
		for (int b = 0; b < m; b++)
		{
			p[b].getstr();
			p[b].getsum();
		}
		for (int c = 0; c < m-1; c++)
		{
			for (int d = c+1; d < m; d++)
			{
				if (p[c] > p[d]) { Mystring t; t = p[c]; p[c] = p[d]; p[d] = t; }
			}
		}
		for (int e = 0; e < m; e++)
		{
			p[e].print();
		}
		cout << endl;
	}
	return 0;
}