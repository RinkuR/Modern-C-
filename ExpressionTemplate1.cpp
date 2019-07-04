#include<iostream>
using namespace std;
class CA
{
	int a, b, c;
};
template<int N> class A
{
public:
	static int size() { return N; }
};

int f1();
double f2();
CA& f3();


void  calc_size()
{
	cout << A<sizeof(f1())>().size() << endl;
	cout << A<sizeof(f2())>().size() << endl;
	cout << A<sizeof(f3())>().size() << endl;
}
void main()
{
	calc_size();
}