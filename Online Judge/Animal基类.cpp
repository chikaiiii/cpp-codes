#include<iostream>
#include<string>
using namespace std;
class Animal
{};
int main()
{
	string s;
	while (cin >> s)
	{
		switch (s[0])
		{
		case 'c': cout << "meow" << endl; break;
		case 'd': cout << "wang" << endl; break;
		case't': cout << "howl" << endl; break;
		}
	}
}