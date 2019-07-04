#include<iostream>
#include<vector>
using namespace std;

class CA
{
private:
	int a, b;
public:
	CA() :a(0), b(0) { cout << "CA default constructor" << endl; }
	CA(const CA &x) :a(x.a), b(x.b) { cout << "CA copy constructor" << endl; }
	CA(CA &&x) : a(move(x.a)), b(move(x.b))  { cout << "CA move copy constructor" << endl; }
};

void main()
{
	vector<CA> v1;
	cout << "after push" << endl;
	v1.push_back(CA());
	cout << "after push" << endl;
	v1.push_back(CA());
}