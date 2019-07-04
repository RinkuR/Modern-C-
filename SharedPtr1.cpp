#include<iostream>
#include<memory>
using namespace std;
class CA
{
public:
	CA() { cout << "CA constructor called" << endl; }
	~CA() { cout << "CA destructor called" << endl; }
};

void fun3(shared_ptr<CA> p)
{
	cout << "inside fun3, shared count:" << p.use_count() << endl;
}

void fun2(shared_ptr<CA> p)
{
	cout << "inside fun2, shared count:" << p.use_count() << endl;
	fun3(p);
}

void fun1(shared_ptr<CA> p)
{
	cout << "inside fun1, shared count:" << p.use_count() << endl;
	fun2(p);
}



int main()
{
	shared_ptr<CA> ptr1(new CA);
	cout << "Before fun1 call, shared count:" << ptr1.use_count() << endl;
	fun1(ptr1);
	cout << "After fun1 call, shared count:" << ptr1.use_count() << endl;
	return 0;
}