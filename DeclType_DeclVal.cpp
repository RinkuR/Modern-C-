#include<iostream>
using namespace std;

class CA
{
public:
	//CA() { }
};

class CB
{
private:
	CB() { }
public:
	static void fun() 
	{ 
		CB(); //create a nameless object
	}
};

void main()
{
	auto x = 10;
	auto y = 2.3;
	//decltype - Declare or tell the expressions result type
	cout << typeid(decltype(x*y)).name() << endl;
	cout << typeid(decltype(CA())).name() << endl;
	//----------------------------------
	//cout << typeid(decltype(CB())).name() << endl;

	// For the above statement to succeed it should be in a position
	// to create a temporary instance of 'CB' kind, as it is not
	// possible for the reason, constructor is in private, Hence ERROR.

	// THE ALTERNATE SOLUTION, using the generic function DECLVAL
	cout << typeid(declval<CB>()).name() << endl;

	CB::fun();
}