#include<iostream>
#include<thread>
#include<mutex>
using namespace std;


struct CA 
{
private:
	mutex mx;
	//recursive_mutex mutex;
	int i;
public:
	CA(int x=100):i(x) {}

	void mul(int x) 
	{
		std::lock_guard<mutex> lock(mx);
		i *= x;
		cout << i << endl;
	}

	void div(int x) 
	{
		std::lock_guard<mutex> lock(mx);
		i /= x;
		cout << i << endl;
	}

	void Arithmetic(int x, int y) 
	{
		std::lock_guard<mutex> lock(mx);
		mul(x);
		div(y);
	}
};

int main()
{
	CA obj1;
	obj1.Arithmetic(10, 20);
}