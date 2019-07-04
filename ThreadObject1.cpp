#include<iostream>
#include<thread>
using namespace std;

void fun()
{
	cout << "fun() called from thread :" << this_thread::get_id() << endl;
}

void main()
{
	thread th1(fun);
	th1.join();    //join is blocking call
	cout << "main thread, id : " << this_thread::get_id() << endl;
   //     th1.join();
}