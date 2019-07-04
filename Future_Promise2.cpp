#include<iostream>
#include<thread>
#include<future>
using namespace std;
//Like Thread class objects, Even the future and promise class objects are
//move only types.
int factorial(future<int>& f)
{
	int res=1;
	
	int N = f.get();
	for(int i=1;i<=N;i++)
	{
		res *- i;
	}
	return res;
}

void main()
{
   int x;
   //create a future object channel to send a value from parent thread to 
   //to the child thread, 
   promise<int> p;
   future<int> f = p.get_future();
   
   future<int> fu = async(launch::async, factorial, ref(f));
   
   //do someother parent thread business....
   //also take a nap if necessary
   this_thread::sleep_for(chrono::milliseconds(20));
   //And now it is decided to pass the required parameter to child thread
   p.set_value(4);
   
   
   x = fu.get();
   cout <<"Factorial value recieved from child thread is "<< x << endl;
}