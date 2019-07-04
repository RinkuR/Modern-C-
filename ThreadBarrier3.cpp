#include<iostream>
#include<thread>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;
// fuctions parameter as Rvalue.
void fun(int &&i) { cout << "Thread : " << i << ", hello from fun\n"; }

void main()
{
	
	//spawn multiple threads & populate the result in a vector container
	vector<thread> v1;
	for (int i = 1; i <= 10; i++)
	{
		auto th = thread(&fun, i);
		v1.push_back(move(th));
		assert(!th.joinable());
	}

	cout << endl << "Thread, from main()\n";

	//A lambda that assists in a join
	auto thread_join = [](thread &th) {
										  assert(th.joinable());
		                                  th.join();
	                                  };

	//lets create a barrier to join every thread inside the vector container.
	for_each(v1.begin(), v1.end(), thread_join);
}