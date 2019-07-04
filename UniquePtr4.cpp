#if 0

#include<iostream>
#include<memory>
#include<functional>
using namespace std;
class CA
{
public:
	CA() { cout << "CA constructor called" << endl; }
	~CA() { cout << "CA destructor called" << endl; }
	void print() { cout << "CA print called :" << this << endl; }
};

void print(size_t size, CA *p)
{
	for (size_t i = 0; i < size; i++)
	{
		p->print();
		p++;
	}
}
int main()
{
	//create an array of instances on the heap
	//Also provide a custom deleter to delete the array of instances.
	unique_ptr<CA,function<void(CA*)>> p{ new CA[5], [](CA *x) {delete[]x; }};

    //unique_ptr<CA>p(new CA[5]); //bad idea
	print(5, p.get());
	
	return 0;
} 
#endif