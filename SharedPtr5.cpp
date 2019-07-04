// ModernSmartPointers.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<memory>
using namespace std;
class CA
{
public:
	CA() { cout << "CA constructor called" << endl; }
	~CA() { cout << "CA destructor called" << endl; }
	void print() { cout << "CA-print called:" << this << endl; }
};


int main()
{
	shared_ptr<CA> ptr1 = make_shared<CA>();
	ptr1.reset();  //reset will work as a conversion function bool   
	if (ptr1)     //if(ptr.operator bool())  internally
		cout << "shared_count :" << ptr1.use_count() << endl;
	else
		cout << "sharing no object - count :" << ptr1.use_count() << endl;
	return 0;
}

//reset will check if both count is zero then only it will free