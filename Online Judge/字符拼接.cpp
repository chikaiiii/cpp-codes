#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		char *p = new char[n];
		for (int i = 0; i < n; i++)
		{
			cin >> *(p + i);
		}
		for (int k = 0; k < n; k++)
		{
			cout << *(p + k);
		}
		cout << endl;
	}
	return 0;
}