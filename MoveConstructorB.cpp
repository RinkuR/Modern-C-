#include<iostream>
#include<string>
using namespace std;

class CA
{
private:
	double d;
	int *p;
	string str;
public:
	CA():d(12.34),p(new int(10)),str("hello") { }
	CA(CA&& rhs) :d(rhs.d), p(rhs.p), str(move(rhs.str))
	{
		cout << "move constructor called" << endl;
		rhs.p = nullptr;
		rhs.str.clear();
	}

	CA& operator =(CA&& rhs)
	{
		delete p;

		d = rhs.d;
		p = rhs.p;
		str = move(rhs.str);
		rhs.p = nullptr;
		rhs.str.clear();
		return *this;
	}
	void print()
	{
		cout << "d = " << d << endl;
		cout << "*p = " << *p << endl;
		cout << "str = " << str << endl;
	}
};

void main()
{
	CA obj1;
	obj1.print();
	cout << "after move " << endl;
	CA obj2(move(obj1));

	cout << "obj2 contents" << endl;
	obj2.print();
}