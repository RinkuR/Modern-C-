#include<iostream>
#include<functional>
using namespace std;
//A recursive lambda that shall be accessible to all functions

auto Recursive_Fib=[](int x) 
{
	function<int(int)> fib = [&fib](int y)
	{
		return y <= 2 ? 1 : fib(y - 1) + fib(y - 2);
	};
		return fib(x);
};

int main()
{
	cout << Recursive_Fib(20) << endl;
	return 0;
}