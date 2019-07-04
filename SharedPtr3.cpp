

#include<iostream>
#include<memory>
using namespace std;
class CA
{
public:
	CA() { cout << "CA constructor called" << endl; }
	~CA() { cout << "CA destructor called" << endl; }
};

class CB
{
private:
	CA * p;
public:
	CB():p(new(nothrow) CA) {}
	~CB() { delete p; }
};

void fun1(shared_ptr<CB> ptr)
{
	cout << "inside fun1, use count:" << ptr.use_count() << endl;
}
int main()
{
	//shared_ptr<CB> ptr1(new CB);
	shared_ptr<CB> ptr1 = make_shared<CB>(); //
	fun1(ptr1);
	return 0;
}
