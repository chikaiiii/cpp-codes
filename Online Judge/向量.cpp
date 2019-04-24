#include<iostream>
using namespace std;
class Vector
{
private:
	double *v;
	int len;
public:
	Vector(int size);
	Vector(double *, int);
	~Vector();
	double &operator[](int i);
	Vector & operator=(Vector &A);
	friend Vector operator+(Vector &A, Vector &B);
	friend Vector operator-(Vector &A, Vector &B);
	friend Vector operator*(Vector &A, Vector &B);
	friend ostream & operator<<(ostream &output, Vector &);
	friend istream & operator>>(istream &input, Vector &);
};
Vector::Vector(int size)
{
	if (size <= 0) {
		cout << "Invalid" << endl; exit(0);
	}
	v = new double[size];
	for (int i = 0; i < size; i++) v[i] = 0;
	len = size;
}
Vector::Vector(double *B, int size)
{
	if (size <= 0)
	{
		cout << "Invalid!" << endl; exit(0);
	}
	v = new double[size];
	len = size;
	for (int i = 0; i < size; i++)
	{
		v[i] = B[i];
	}
}
Vector::~Vector()
{
	len = 0;
}
Vector & Vector::operator=(Vector &A)
{
	if (len == A.len)
	{
		for (int i = 0; i < len; i++)
		{
			v[i] = A.v[i];
		}
		return *this;
	}
}
double & Vector::operator[](int i)
{
	if (i >= 0 && i < len) return *(v + i);
	exit(0);
}
Vector operator+ ( Vector &A,  Vector &B)
{
	int s = A.len;
	double *temp = new double[s];
	if (s == B.len)
	{
		for (int i = 0; i < s; i++)
		{
			temp[i] = A.v[i] + B.v[i];
		}
		for (int i = 0; i < s; i++)
		{
			cout << temp[i] << " ";
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
	int s = A.len;
	double *temp = new double[s];
	if (s == B.len)
	{
		for (int i = 0; i < s; i++)
		{
			temp[i] = A.v[i] - B.v[i];
		}
		for (int i = 0; i < s; i++)
		{
			cout << temp[i] << " ";
		}
	}
	else
	{
		cout << "Operator - failed" << endl;
		exit(0);
	}
}
Vector operator* ( Vector &A,  Vector &B)
{
	int s = A.len;
	double *temp = new double[s];
	if (s == B.len)
	{
		for (int i = 0; i < s; i++)
		{
			temp[i] = A.v[i] * B.v[i];
		}
		for (int i = 0; i < s; i++)
		{
			cout << temp[i] << " ";
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
	for (int i = 0; i < A.len; i++)
	{
		output << A.v[i] << " ";
	}
	return output;
}
istream & operator>>(istream & input, Vector &A)
{
	for (int i = 0; i < A.len; i++)
	{
		input >> A.v[i];
	}
	return input;
}
int main()
{
	int k;
	char fuhao;
	cout << "请输入向量长度" << endl;
	cin >> k;
	Vector a(k), b(k), c(k);
	cout << "请输入向量A" << endl;
	cin >> a;
	cout << "请输入向量B" << endl;
	cin >> b;
	cout << "请选择要执行的运算" << endl;
	cin >> fuhao;
	switch (fuhao)
	{
	case '+': a + b;cout<<endl; break;
	case '-': a - b;cout<<endl; break;
	case '*': a*b;cout<<endl; break;
	case '=':a = b; cout << endl; break;
	}
	system("pause");
	return 0;
}