#include<iostream>
#include<mutex>
#include<thread>
#include<future>
using namespace std;

once_flag Once;
int Business1()
{
	int x = 0;
	auto lm = [&]() ->int
	{
		cout << "inside lambda" << endl;
		x = 200;
		return x;
	};
	call_once(Once, lm);
	return x;
}
void main()
{
	future<int> f1 = async(Business1);
	cout << f1.get() << endl;
	cout << "-----------------" << endl;
	future<int> f2 = async(Business1);
	cout << f2.get() << endl;
}