#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	long long a, b=0;
	ifstream infile("d:\\D1T1_2.in");
	while (infile >> a) b += a;
	cout <<std::fixed<< b << endl;
	return 0;
}
