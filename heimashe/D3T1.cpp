#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	string input;
	int ans=0;
	ifstream infile("d:\\D3T1_1.in");
	getline(infile, input);
	for(int i=0;i<input.size();i++)
	{if (input[i] >= 65 && input[i]<= 90) ans += (input[i] - 64)*(i+1);
		if (input[i]>= 97 && input[i]<= 122) ans += (input[i] - 70)*(i+1);
	}
	cout << ans << endl;
	return 0;
}