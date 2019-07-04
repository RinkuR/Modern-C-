#include<iostream>
using namespace std;
//Generalized return type in C++ 14
//Addressing multiple return statements was an issue in C++11
auto fun1() -> double
{
	auto a = 10.32;
	cout << "fun1 called" << endl;
	return a;
}
auto fun2() -> double
{
	auto a = 10;
	cout << "fun2 called" << endl;
	return a;
}
void main()
{
	int x = 2;
	//lambda
	auto lm = [=]()
	    {
		if (x == 1)
			return (fun1() * 3);
		else
			return (fun2() * 4);
	    };
	//--- consume the lambda
	cout << lm();
}