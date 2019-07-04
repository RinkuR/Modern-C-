#include<iostream>
#include<thread>
#include<vector>
#include<algorithm>
using namespace std;

void main()
{
	//spawn multiple threads & populate the result in a vector container
	vector<thread> v1;
	for (int i = 1; i <= 10; i++)
	{
		v1.push_back(thread([i]() {cout << "Thread : " << i << ", hello from lambda\n"; }));
	}

	cout << endl << "Thread, from main()\n";

	//A lambda that assists in a join
	auto thread_join = [](thread &th) {th.join(); };

	//lets create a barrier to join every thread inside the vector container.
	for_each(v1.begin(), v1.end(), thread_join);
}