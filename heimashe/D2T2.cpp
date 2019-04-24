#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
bool sushu(int x);
int main()
{
	int k,ans=0;
	int i = 0;
	ifstream infile("d:\\D2T2.in");
	infile >> k;
	if (sushu(k)) cout << ans<< endl;
	else {
		int key = 1;
		while (key)
		{
			k++;
			i++;
			if (sushu(k)) key = 0;
		}
		key = 1;
		k = k - i;
		while (key)
		{
			k--;
			i++;
			if (sushu(k)) key = 0;
		}
	}
	cout << i << endl;
}
bool sushu(int x)
{
	int t = int(sqrt(double(x)));
	int m = 2;
	while (x % m && m <= t)
		m++;
	if (m > t) return true;
	else return false;
}