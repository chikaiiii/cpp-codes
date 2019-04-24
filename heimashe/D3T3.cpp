#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> v1, v2;
	int m;
	int key = 1, i = 0;
	long long total=0;
	ifstream infile("d:\\D3T3_update.in");
	infile >> m;
	while (key)
	{
		int temp;
		infile >> temp;
		v1.push_back(temp);
		i++;
		if (i >= m) key = 0;
	}
	key = 1;
	i = 0;
	while (key)
	{
		int temp;
		infile >> temp;
		v2.push_back(temp);
		i++;
		if (i >= m) key = 0;
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int k = 0; k < v1.size(); k++)
	{
		v1[k] = v1[k] * v2[k];
	}
	for (int j = 0; j < v1.size(); j++)
	{
		total += v1[j];
	}
	cout << total<< endl;
	return 0;
}