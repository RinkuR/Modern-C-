#include<iostream>
#include<thread>
#include<future>
using namespace std;

class CA
{
private:
	int a, b;
public:
	CA(int x = 0, int y = 0) :a(x), b(y) { cout << "CA constructor" << endl; }
	void print()const { cout << "CA-print, a=" << a << ",b=" << b << endl; }
	void operator()(int x, int y) 
	{ 
		cout << "thread id:" << this_thread::get_id() << endl;
		cout << "CA-Functor, called" << endl; a = x; b = y; 
	}
};

void fun1() { cout << "global fun called" << endl; }
void main()
{
	CA obj(10,20);
	/*Launching thread's  thru 'Async' function. */
	async(fun1);  //launch a thread with global function

	cout << "----------------" << endl;

	async(obj, 60, 70); //launch a thread with FUNCTOR
	obj.print();

	cout << "----------------" << endl;
	CA obj3(300, 400);
	future<void> f1=async(&CA::print, obj3);
	cout << "----------------" << endl;
	CA obj2(30, 40);
	future<void> f2 = async(launch::deferred, &CA::print, obj2);
	//...some business here
	//now spawn the thread whose handle is future 'f'
	f2.get();  //It is a call_once function.	
}