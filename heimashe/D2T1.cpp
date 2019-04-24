#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int m,n,t,ans=0;
	ifstream infile("d:\\D2T1_1.in");
	infile >> m;
	infile >> n;
	while (infile >> t)
	{
		if (t <= m) ans++;
	}
	cout << ans << endl;
	return 0;
}