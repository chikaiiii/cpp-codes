#include<iostream>
using namespace std;
int main()
{
	int n, k;
	while (cin >> n)
	{
		int *temp = new int[n];
		int i = 0;
		while (i!=n)
		{
			cin >> *(temp +i);
			i++;
		}
		cin >> k;
		cout << *(temp + (k - 1)) << endl;
		delete []temp;
		temp = NULL;
	}
}