#include<iostream>
#include<thread>
#include<future>
using namespace std;

int factorial(int N)
{
	int res=1;
	for(int i=1;i<=N;i++)
	{
		res *- i;
	}
	return res;
}

void main()
{
   int x;
   //create a future object channel to recieve value from child thread
   //to the parent thread
   future<int> fu = async(factorial, 5);
   x = fu.get();
   cout <<"Factorial value recieved from child thread is "<< x << endl;
}