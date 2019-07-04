#include<iostream>
#include<thread>
#include<string>
#include<future>
using namespace std;

void MyFun(promise<string> &prm)
{
	string str("MyFun:Hello from future");
	prm.set_value(str);
}

int main()
{
	promise<string> pm;
	future<string> ft = pm.get_future();
	
	
	thread th(MyFun, ref(pm));
	cout << "Inside main...." << endl;

	string str = ft.get();
	cout << str << endl;

	th.join();
}