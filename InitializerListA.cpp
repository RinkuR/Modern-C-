#include<iostream>
#include<initializer_list>
using namespace std;

class CA
{
private:
	int arr[5];
public:
	CA(const initializer_list<int> &x) 
	{
		int i = 0;
		if (x.size() <= 5)
		{
			for (auto &val : x)
			{
				arr[i] = val;
				++i;
			}
		}
		else
			cout << "Excess parameters, initialization failed" << endl;
	}

	void print()
	{
		for (auto &val : arr)
		{
			cout << val << ",";
		}
		cout << endl;
	}
};

void main()
{
	CA obj1{ 10,20,30,40,50 };
	obj1.print();
}