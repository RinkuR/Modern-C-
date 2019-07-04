#include<iostream>
using namespace std;
class CA
{
private:
	int a, b;
public:
	CA() :a(0), b(0) { cout << "CA default constructor" << endl; }
	CA(int x) :a(x), b(x) { cout << "CA one arg. constructor" << endl; }
	CA(int x, int y) :a(x), b(y) { cout << "CA two arg. constructor" << endl; }
	CA(const CA& x) :a(x.a), b(x.b) { cout << "CA copy constructor" << endl; }
	~CA() { cout << "CA destructor" << endl; }
	void print()const { cout << "a =" << a << ",b=" << b << endl; }
};

void main()
{
	//A collection of integers dynamically created and initialized
	int *p1 = new int[5]{ 10,20,30,40,50 };
	CA obj1;
	CA* p2 = new CA[4]{ {}, {10},{20,30},{obj1} };
	
	//prefer the above approach over the following syntax
	CA* p3 = new CA[4]{ (10),(20,30),(obj1) };
	p3[1].print();

	delete[]p2;
	delete[]p3;
}