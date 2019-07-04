#include<iostream>
using namespace std;

class CA
{
private:
	int a{};
	int b{ 20 };
	float c = 12.34f;
	int sum = a + b;
	double val = compute();
public:
	double compute()
	{
		return c* 45.56;
	}
	void print()
	{
		cout << "a =" << a << endl;
		cout << "b =" << b << endl;
		cout << "c =" << c << endl;
		cout << "sum =" << sum << endl;
		cout << "val =" << val << endl;
	}
};
//------------------
void main()
{
	CA obj1;
	obj1.print();
}