#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void main()
{
	list<int> ls1;
	for (int i = 1; i <= 10; i++)
		ls1.push_back(i);

	//traverse the list - C++11 APPROACH
	
	//for_each(ls1.begin(), ls1.end(), [](const int &x) {cout << x << ","; });
		
	//cout << endl;
	//***************************************
	auto lm = [](const int &x) {cout << x << ","; };
	for_each(ls1.begin(), ls1.end(), lm);
	//*******************************************
	//traverse the list - C++14 APPROACH, NOW 'auto' CAN BE USED in the formal parameter list
	for_each(begin(ls1),end(ls1),[](const auto &x)
	{
		cout << typeid(x).name() << endl;
		cout << x << ",";
	}
	);
	cout << endl;
	
}