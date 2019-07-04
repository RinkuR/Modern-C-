#include<iostream>
#include<string>
#include<future>
#include<vector>
#include<chrono>
#include<algorithm>
using namespace std;

int main()
{
	cout << "Main thread id:" << this_thread::get_id() << endl;
	vector<future<void>> futures;
	for (int i = 1; i <= 10; i++)
	{
		auto fut = async([]()
		{
			this_thread::sleep_for(chrono::seconds(2));
			cout << "Task id:" << this_thread::get_id() << endl;
		});
		futures.push_back(move(fut));

	}
	for_each(futures.begin(), futures.end(), [](future<void> &x)
	                                                 { x.wait(); });

	//this_thread::sleep_for(chrono::seconds(10));
}