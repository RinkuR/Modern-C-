
#include<iostream>
#include<memory>
using namespace std;
class CA
{
public:
	CA() { cout << "CA constructor called" << endl; }
	~CA() { cout << "CA destructor called" << endl; }
	void print() { cout << "CA-print called:" << this << endl; }
};

int main()
{
	shared_ptr<CA> sp1 = make_shared<CA>();
	
	if (sp1.unique())
		cout << "It is unique" << endl;
	else
		cout << "It is not unique" << endl;
	cout << "-------------------" << endl;
	//shared_ptr<CA> sp2(sp1);
	weak_ptr<CA> sp2(sp1);
	if (sp1.unique())
		cout << "It is unique" << endl;
	else
		cout << "It is not unique" << endl;
}
