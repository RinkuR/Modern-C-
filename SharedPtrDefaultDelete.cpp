 

#include<iostream>
#include<memory>
using namespace std;
class CA
{
public:
	CA() { cout << "CA constructor called" << endl; }
	~CA() { cout << "CA destructor called" << endl; }
	void print() { cout << "CA print called :" << this << endl; }
};


int main()
{ 
	//std::shared_ptr<int> shared_good(new int[10], std::default_delete<int[]>());
	//create an array of instances on the heap
	shared_ptr<CA> p( new CA[5], default_delete<CA[]>());

	auto x = p.get();
	[=](int size) mutable
	{
		int i = 0;
		do
		{
			x[i].print();
			i++;
		} while (i < size);
	}(5);
	return 0;
}
 