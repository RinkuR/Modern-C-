#include<iostream>
using namespace std;

class AnyCast
{
private:
public:
	 template<typename T1, typename T2> static T1* any_cast(T2 *p)
	{
		if (typeid(T1) == typeid(T2))
		{
			cout << "cast successfull" << endl;
			return p;
		}
		else
		{
			cout << "bad cast" << endl;
			return nullptr;
		}
	}
};
class CA
{
public:
	void fun() { cout << "CA fun called" << endl; }
};
class CB
{
public:
	void fun() { cout << "CB fun called" << endl; }
};
//****** consumer code ******
void main()
{
	CA obj1;
	CB obj2;
	if (CA *q1 = AnyCast::any_cast<CA>(&obj1))
	{
		q1->fun();
	}
	else
	{
		cout << "Type not CA, casting failed" << endl;
	}
}