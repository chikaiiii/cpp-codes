#include<iostream>
using namespace std;
class Integer
{
public:
	Integer()
	{
		n = 5;
	}
protected:
	int n;
};
class Vector :public Integer
{
public:
	Vector();
	Vector(int *,int size);
	~Vector();
	int &operator[](int i);
	friend Vector operator+(Vector &A, Vector &B);
	friend Vector operator-(Vector &A, Vector &B);
	friend Vector operator*(Vector &A, Vector &B);
	friend ostream & operator<<(ostream &output, Vector &);
	friend istream & operator>>(istream &input, Vector &);
protected:
	int *v;
};
Vector::Vector()
{
	if (n <= 0) {
		cout << "Invalid" << endl; 
	}
	v = new int[n];
	for (int i = 0; i < n; i++) v[i] = 0;
}
Vector::Vector(int *B,int size)
{
	if (n <= 0)
	{
		cout << "Invalid!" << endl; 
	}
	v = new int[n];
	for (int i = 0; i < n; i++)
	{
		v[i] = B[i];
	}
}
Vector::~Vector()
{
	n = 0;
}
int & Vector::operator[](int i)
{
	if (i >= 0 && i < n) return *(v + i);
	exit(0);
}
Vector operator+ (Vector &A, Vector &B)
{
	int s = A.n;
	int *temp = new int[s];
	if (s == B.n)
	{
		for (int i = 0; i < s; i++)
		{
			temp[i] = A.v[i] + B.v[i];
		}
		for (int i = 0; i < s; i++)
		{
			cout << temp[i]<<" ";
		}
	}
	else
	{
		cout << "Operator + failed" << endl;
		exit(0);
	}
}
Vector operator- (Vector &A, Vector &B)
{
	int s = A.n;
	int *temp = new int[s];
	if (s == B.n)
	{
		for (int i = 0; i < s; i++)
		{
			temp[i] = A.v[i] - B.v[i];
		}
		for (int i = 0; i < s; i++)
		{
			cout << temp[i]<<" ";
		}
	}
	else
	{
		cout << "Operator - failed" << endl;
		exit(0);
	}
}
Vector operator* (Vector &A, Vector &B)
{
	int s = A.n;
	int *temp = new int[s];
	if (s == B.n)
	{
		for (int i = 0; i < s; i++)
		{
			temp[i] = A.v[i] * B.v[i];
		}
		for (int i = 0; i < s; i++)
		{
			cout << temp[i]<<" ";
		}
	}
	else
	{
		cout << "Operator * failed" << endl;
		exit(0);
	}
}
ostream & operator<<(ostream & output, Vector &A)
{
	for (int i = 0; i < A.n; i++)
	{
		output << A.v[i] << " ";
	}
	return output;
}
istream & operator>>(istream & input, Vector &A)
{
	for (int i = 0; i < A.n; i++)
	{
		input >> A.v[i];
	}
	return input;
}
int main()
{
	char fuhao;
	Vector A, B,C;
	cout << "请输入向量A：" << endl;
	cin >> A;
	cout << "请输入向量B:" << endl;
	cin >> B;
	cout << "请输入运算符号：" << endl;
	cin >> fuhao;
	switch (fuhao)
	{
	case '+': A + B; break;
	case '-': A - B; break;
	case '*':A*B; break;
	default:break;
	}
	system("pause");
	return 0;
}