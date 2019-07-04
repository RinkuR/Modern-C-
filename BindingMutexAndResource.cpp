#include<iostream>
#include<thread>
#include<mutex>
#include<fstream>
#include<string>
using namespace std;

/*
* A resource that is bound to be accesses by multiples thread's must be
* bound to-gether along with its mutex. And we have to ensure that this resource
* never gets accessed outside the bound of the mutex.
*/

class MyFile
{
private:
	mutex m;
	ofstream Datafile;
public:
	MyFile() { Datafile.open("data.txt"); }
	void Write(string s, int val)
	{
		lock_guard<mutex> guard(m);
		Datafile << s << ":" << val << endl;
	}
	~MyFile() 
	{ 
		Datafile << "----FILE CLOSED---" << endl;
		Datafile.close(); 
	}
	/*
	    Always ensure the resource 'Datafile' never gets exposed to the outside world.
		1- Never return 'Datafile' from a function
		2- Never pass 'Datafile' as a parameter to a user-defined function.
	* By doing so the resource would slip from the control of 'mutex'
*/
};

void Decrement(MyFile &x)
{
	for (int i = -1; i > -100; i--)
	{
		x.Write("Decrement ", i);
	}
}
void Increment(MyFile &x)
{
	for (int i = 1; i < 100; i++)
	{
		x.Write("Increment ", i);
	}
}

void main()  //Parent thread
{
	MyFile obj1;
	thread th1(Decrement, ref(obj1));
	thread th2(Increment, ref(obj1));
	th1.join();
	th2.join();
}