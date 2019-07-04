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
	shared_ptr<CA> ptr1(new CA());
	shared_ptr<CA> ptr2(ptr1);
	cout << "objects shared" << ptr1.use_count() << endl;
	weak_ptr<CA> wk1 = ptr1;
	cout << "objects shared after weak reference" << wk1.use_count() << endl;
	auto ptr3 = wk1.lock();  //lock will use to access data it will return shared ptr
	ptr1->print();
	ptr2->print();
	ptr3->print();
	cout << "shared count, after acquiring lock:" << ptr1.use_count() << endl;
	cout << "weak count after providing lock:" << wk1.use_count() << endl; //it will give shared count info
	return 0; 
}

