#include < iostream >
using namespace std;
// * 仅提交以下代码 * //
template < typename T >
class A
{
public:
	A(int num)
	{
		n = num;
		a = new T[n];
	}
	void Set(int x)
	{
		cin >> a[x];
	}
	int Search(T s)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] == s) return i;
		}
		return -1;
	}
private:
	int n;
	T *a;
};
// * 仅提交以上代码 * //
int main()
{
	int i, j, k;
	int m;
	double n;
	while (cin >> i >> j)
	{
		A<int> intAry(i);
		A< double> douAry(j);
		for (k = 0; k < i; k++)
		{
			intAry.Set(k);
		}//输入整型数组元素
		for (k = 0; k < j; k++)
		{
			douAry.Set(k);
		}//输入浮点型数组元素
		cin >> m >> n;
		cout << "The number of " << m << " in intAry is " << intAry.Search(m) << endl;
		cout << "The number of " << n << " in douAry is " << douAry.Search(n) << endl;
	}
}
