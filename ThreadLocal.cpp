#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
/*
-A thread_local object comes into existence when a thread starts 
                    and is destroyed when the thread ends. 

-Each thread has its own instance of a thread-Local object.
*/
thread_local int globalVar = 0;

mutex mu;

void Print(int value)
{
	lock_guard<mutex> lock(mu);
	cout << "Value of globalVar in thread " << this_thread::get_id() << " is " << globalVar << endl;
}

void thread_Func(int newVal)
{
	globalVar = newVal;
	Print(globalVar);
}
int main()
{
	globalVar = 1;
	thread t1(thread_Func, 5);
	thread t2(thread_Func, 20);
	t1.join();
	t2.join();
	cout << "Value of globalVar in MAIN thread is " << globalVar << endl;
	return 0;
}