#include<iostream>
using namespace std;
template<class T>
T&& _forward(typename remove_reference<T>::type t) 
{
	cout << __FUNCSIG__ << endl;
	return static_cast<T&&>(t);
}
template <typename T1, typename T2>void wrapper(T1&& e1, T2&& e2) 
{
	cout << __FUNCSIG__ << endl;
	cout << "contents of e1 an e2 before forwarding to func =" << e1 << "," << e2 << endl;
	func(_forward<T1>(e1), _forward<T2>(e2));
	cout << "contents of e1 an e2 after forwarding to func =" << e1 << "," << e2 << endl;
}

template<typename T1, typename T2> void func(T1 x, T2 y)
{
	cout << __FUNCSIG__ << endl;
	x = x + 10;
	y = y + 12.34f;
}

void main()
{
	wrapper(100, 12.34f);
	cout << "-----------" << endl;
	int a = 200;
	float b = 34.56f;
	wrapper(a, b);
	cout << "-----------" << endl;
	wrapper(100, b);
	cout << "-----------" << endl;
	wrapper(a, 12.34f);
}