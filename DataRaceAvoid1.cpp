#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex mu;

void Decrement()
{
	mu.lock();
	{
		for (int i = -1; i > -100; i--)
		{
			cout << "Decrement :" << i << endl;
		}
		mu.unlock();
	}
}
void Increment()
{
	mu.lock();
	{
		for (int i = 1; i < 100; i++)
		{
			cout << "Increment :" << i << endl;
		}
	}
	mu.unlock();
}
void main()
{
	thread th1(Increment);
	thread th2(Decrement);
	th1.join();
	th2.join();
}