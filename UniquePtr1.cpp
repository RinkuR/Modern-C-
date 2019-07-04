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

void fun1(unique_ptr<CA> p)
{
	cout << "inside fun1, ";
	p->print();
}
int main()
{
	//unique_ptr<CA> ptr1(new CA);
	unique_ptr<CA> ptr1 = make_unique<CA>();
	cout << "Call to 'print' before transferring ownership ";
	ptr1->print();

	//fun1(ptr1);    //Error, as it is not COPYABLE
	fun1(move(ptr1)); //OK, Being a MOVEABLE type, we are moving the same. 

	cout << "Call to 'print' after transferring ownership ";
	if ((ptr1.get() != nullptr))
		ptr1->print();
	else
		cout << "Cannot call CA-print" << endl;

	return 0;
}