#include<iostream>
using namespace std;
template<typename T>
class Array{};
int main()
{
	int n1, n2, n3, n4;
	cin >> n1;
	int* arr1 = new int[n1];
	for (int i = 0; i < n1; i++)
	{
		cin >> arr1[i];
	}
	cin >> n2;
	int* arr2 = new int[n2];
	for (int i = 0; i < n2; i++)
	{
		cin >> arr2[i];
	}
	cin >> n3;
	double* arr3 = new double[n3];
	for (int i = 0; i < n3; i++)
	{
		cin >> arr3[i];
	}
	cin >> n4;
	double* arr4 = new double[n4];
	for (int i = 0; i < n4; i++)
	{
		cin >> arr4[i];
	}
	cout << "[";
	for (int i = 0; i < n1; i++)
	{
		cout << arr1[i] << ",";
	}
	cout << arr2[0];
	for (int i = 1; i < n2; i++)
	{
		 cout <<","  <<arr2[i] ;
	}
	cout << "]";
	cout << endl;
	cout << "[";
	for (int i = 0; i < n3; i++)
	{
		 cout << arr3[i] << ",";
	}
	cout << arr4[0];
	for (int i = 1; i < n4; i++)
	{
		cout <<","<< arr4[i];
	}
	cout << "]";
	cout << endl;
	return 0;
}