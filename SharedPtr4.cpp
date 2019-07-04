 

#include<iostream>
#include<memory>
using namespace std;
class CA
{
public:
	CA(int x=0, int y=0) 
	{ 
		cout << "CA constructor called" << endl; 
		cout <<"x =" << x <<",y="<< y << endl;
	}
	~CA() { cout << "CA destructor called" << endl; }
	void print() { cout << "CA print called :" << this << endl; }
};


int main()
{
	/*
	- create an array of instances of type 'CA' and provide its 
	  handle to a shared_ptr instance
	*/
	shared_ptr<CA> ptr1(new CA[5]{ {}, {10}, { 10,20 }, { 40 }, { 50,60 } }, [](CA *q) {delete[] q; });

	CA *q =ptr1.get();
	[=](int size) mutable   //A Once use lambda
	{
		int i = 0;
		do
		{
			q[i].print();
			++i;
		} while (i < size);
	}(5);  //one use call lambda

	return 0;
}
 