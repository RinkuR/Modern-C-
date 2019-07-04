#include<iostream>
#include<type_traits>
using namespace std;

void main()
{
	int x = 100;
	//int&& p = (remove_reference_t<int>&&) x;
	int&& p = move(x);
	cout << "data type of p is " << typeid(p).name() << endl;
	cout << x << endl;
	cout << p << endl;
}