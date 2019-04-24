#include<iostream>
#include<cmath>
using namespace std;
class Prime
{
public:
	Prime(int x)
	{
		dataInt = x;
	}
	bool isprime()
	{
		int k = int(sqrt((double)dataInt));
		int key = 1;
		for (int i = 2; i <= k; i++)
		{
			if (dataInt % i == 0) {
				key = 0; break;
			}
		}
		if (key) return true;
		else return false;
	}
	bool plalindrome()
	{
		int n1=dataInt, n2=0;
		while (n1 > 0)
		{
			n2 = n2 * 10 + (n1 % 10);
			n1 /= 10;
		}
		if (n2 == dataInt) return true;
		else return false;
	}
private:
	int dataInt;
};
int main()
{
	int n;
	while (cin >> n)
	{
		Prime a(n);
		if (a.isprime() && a.plalindrome()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}