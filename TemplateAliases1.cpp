#include<iostream>
using namespace std;

template<typename T> class CA
{
	//typedef T value;
	using value = T;
	using reference = T&;
	value a{}, b{};
	reference c;
public:
	CA(int x = 0) :c(x){ }
	void print(int &x)
	{
		c = x;
		cout <<"a=" << a << "b =" << b << endl;
		cout << c << endl;
	}
};

void main()
{
	CA<int> obj1(100);
	cout << "size of CA<int>" << sizeof(obj1) << endl;
	int z = 100;
	obj1.print(z);
	cout << z << endl;
}