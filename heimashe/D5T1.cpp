#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
const long long P = 1e9 + 7;
const int MAX = 3e5 + 5;
int n;
int pc[MAX];
long long pow_2[MAX];

void quicksort(int* arr, int low, int high)
{
	if (low >= high) return;

	int k = arr[low], tmp;
	int lf = low, rh = high;
	while (lf < rh)
	{
		while (arr[rh] >= k && lf < rh) --rh;
		while (arr[lf] <= k && lf < rh) ++lf;
		if (lf < rh)
		{
			tmp = arr[rh];
			arr[rh] = arr[lf];
			arr[lf] = tmp;
		}
	}
	arr[low] = arr[lf];
	arr[lf] = k;
	quicksort(arr, low, lf - 1);
	quicksort(arr, rh + 1, high);
}

void initial()
{
	pow_2[0] = 1;
	for (int i = 1; i < n; ++i)
		pow_2[i] = (pow_2[i - 1] << 1) % P;
}

int main()
{
	ifstream infile("d:\\answer\\D5T1.in");
	infile >> n;
	initial();
	for (int i = 0; i < n; ++i)
		infile >> pc[i];
	quicksort(pc, 0, n - 1);

	long long sum = 0, t_sum = 0;
	for (int i = 1; i < n; ++i)
	{
		t_sum = ((t_sum << 1) % P + pc[i - 1]) % P;
		sum = (sum + (pow_2[i] - 1) * pc[i] - t_sum) % P;
	}
	cout << sum;
	infile.close();
	return 0;
}