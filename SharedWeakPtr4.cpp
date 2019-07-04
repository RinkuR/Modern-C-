#include<iostream>
#include<memory>
using namespace std;
class CA
{
private:
	//shared_ptr<CA> p1;
	weak_ptr<CA> p1;
public:
	CA() { cout << "CA constructor called" << endl; }
	~CA() { cout << "CA destructor called" << endl; }
	void print() { cout << "CA-print called:" << this << endl; }
	void Set(shared_ptr<CA> x) { p1 = x; }
};

int main()
{
	shared_ptr<CA> ptr1 = make_shared<CA>();
	shared_ptr<CA> ptr2 = make_shared<CA>();

	ptr1->Set(ptr2);
	ptr2->Set(ptr1);  //this cyclic refrence not dropping handle so to avoid shared ptr use weak_ptr// because weak_ptr never give info 
                            //for shared_ptr
    return 0;
}