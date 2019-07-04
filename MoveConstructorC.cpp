#include<iostream>
using namespace std;
//A class whose instance is move only.

class CA
{
private:
	int *p;
public:
	CA() :p(new int(10)) { }
	~CA() { delete p; }
	//Supress the traditional copy constructor and assignment function
	CA(const CA &x) = delete;
	CA& operator =(const CA &x) = delete;

	//Move constructor and Move assignment functions
	CA(CA &&x)
	{
		*this = move(x);
	}
	CA& operator =(CA&& x)
	{
		if (this == &x)
			return *this;
		else
		{
			p = x.p;
			x.p = nullptr;
			return *this;
		}
	}
};

void main()
{
	CA obj1;   //ok
	//CA obj2(obj1);  //ERROR, cannot copy
	CA obj2(move(obj1));  //ok

	CA obj3;
	obj3 = move(obj2);
}