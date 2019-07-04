#include<iostream>
#include<thread>
#include<future>
using namespace std;

void fun1() { cout << "Welcome "; }
void fun2() { cout << "To "; }
void fun3() { cout << "C++ "; }
void fun4() { cout << "Multithreading "; }

void main()
{
	cout << "inside main thread" << endl;
	/*thread th1(fun1);
	thread th2(fun2);
	thread th3(fun3);
	thread th4(fun4);
	th1.join();
	th2.join();
	th3.join();
	th4.join();*/

	//spawn threads with 'async'
	async(launch::async, fun1);
	async(launch::async, fun2);
	async(launch::async, fun3);
	async(launch::async, fun4);
}