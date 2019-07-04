#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

once_flag Once;
void Business1()
{
	auto lm = []() {cout << "inside lambda" << endl; };
	call_once(Once, lm);
}
void main()
{
	thread th1(Business1);
	th1.join();
	thread th2(Business1);
	th2.join();
}