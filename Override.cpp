#include<iostream>
using namespace std;

class Base
{
public:
	virtual void fun(int x){  }
};

class Derived :public Base
{
public:
	void fun(int x) override   //OK
	{
		//….
	}
	void fun(double x) override  //ERROR
	{
		//…
	}
};
