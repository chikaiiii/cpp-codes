#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
struct course
{
	int start, end;
};
bool min(course x, course y)
{
	return x.end < y.end;
}
int main()
{
	int n;
	ifstream infile("d:\\answer\\D4T1.in");
	infile >> n;
	course* v = new course[n];
	for (int i = 0; i < n; i++)
	{
		infile >> v[i].start >> v[i].end;
	}
	sort(v+0, v + n,min);
	int ans=1;
	int temp = v[0].end;
	for (int i = 1; i < n; i++)
	{
		if (v[i].start >= temp) {
			ans++; temp = v[i].end;
		}
	}
	cout << ans << endl;
	return 0;
}