#include<iostream>
#include<memory>
using namespace std;
class CA
{
	int a, b;
public:
	CA(int x=0, int y=0):a(x),b(y) { cout << "CA constructor called" << endl; }
	~CA() { cout << "CA destructor called" << endl; }
	void print() { cout << "CA-print called:" << this << endl; }
	int GetFirst() {	return a;	}
	int GetSecond() { return b; }
};

int main()
{
	shared_ptr<CA> sp1 = make_shared<CA>(10, 20);

	shared_ptr<int> data1 = make_shared<int>(sp1->GetFirst());
	shared_ptr<int> data2 = make_shared<int>(sp1->GetSecond());
	cout << boolalpha << *data1 << " is less than " <<  *data2 << ":"<< (data1 < data2) << endl;

	cout << boolalpha << *data1 << " is before " << *data2 << ":" << data1.owner_before(data2) << endl;
	cout << boolalpha << *data2 << " is before " << *data1 << ":" << data2.owner_before(data1) << endl;
    // order of shared ptr objects
}