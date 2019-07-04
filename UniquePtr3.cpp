#include<iostream>
#include<memory>
using namespace std;
class CA
{
public:
	CA() { cout << "CA constructor called" << endl; }
	~CA() { cout << "CA destructor called" << endl; }
	void print() { cout << "CA print called" << endl; }
};

class CB
{
private:
	CA * p;
public:
	CB() :p(new(nothrow) CA) {}
	~CB() { delete p; }
	void print() { p->print(); }
};

void fun(unique_ptr<CB> p)
{
	cout << "inside fun :";
	p->print();
}

int main()
{
	unique_ptr<CB> ptr1(new CB);
	cout << "inside main:, before transferring ownership" << endl;
	ptr1->print();

	fun(move(ptr1));  //Transfer ownership
	cout << "inside main:, after transferring ownership" << endl;
	if ((ptr1.get() != nullptr))
		ptr1->print();
	else
		cout << "Cannot call CB-print" << endl;
	return 0;
}