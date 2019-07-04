#include<iostream>
#include<thread>
using namespace std;

void fun1()
{
	cout << "Id of fun1 thread " << this_thread::get_id() << endl;
}

void main()
{
	thread t1(&fun1);
	t1.join();
}