#include<iostream>
#include<vector>
#include<memory>
using namespace std;

class CA
{
private:
	int a = 0, b = 0;
public:
	CA() = default;
	CA(int x, int y) :a(x), b(y) { cout << "Two arg. constructor" << endl; }
	void print() const { cout << "a = " << a << ",b=" << b << endl; }
	~CA() { cout << "CA destructor" << endl; }
};

void main()
{
	vector<unique_ptr<CA>> v1;
	for (auto &x : { 1,2,3,4,5 })
	{
		auto i = make_unique<CA>(x, x + 10);
		v1.push_back(move(i));

		//v1.push_back(make_unique<CA>(x, x + 10));
	}
	/*auto itr = v1.begin();
	while (itr != v1.end())
	{
		auto p = itr->get();
		p->print();
		itr++;
	}*/
	for (auto &itr : v1)
	{
		itr->print();
	}
}