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

int main()
{
	unique_ptr<CB> ptr1(new CB);
	ptr1->print();
	return 0;
}

//cb managing ca internally