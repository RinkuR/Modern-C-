#include<iostream>
using namespace std;
class CA
{
private:
	int a, b;
	CA(int x, int y) :a(x), b(y) { cout << "CA two arg.constructor" << endl; }
public:
	CA() :CA(10, 20){ cout << "CA default constructor" << endl; }

	CA(int x) :CA(x, x) { cout << "CA one arg. constructor" << endl; }
};

void main()
{
	CA obj1(300);
}