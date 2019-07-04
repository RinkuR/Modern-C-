#include<iostream>
#include<functional>
#include<memory>
using namespace std;
class CA
{
public:
	CA() { cout << "CA default constructor" << endl; }
	void print() { cout << "CA print called" << endl; }
	~CA() { cout << "CA destructor" << endl; }
};


void main()
{
	unique_ptr<CA> obj(new CA);
	/*    NOT ALLOWED BY VALUE
	auto lm = [=]()
	{
	cout << "inside lambda" << endl;
	obj->print();
	};
	*/
	/*  ALLOWED BY REFERENCE
	auto lm = [&]() 
				{
					cout << "inside lambda" << endl; 
					obj->print();
				};
	lm();
	*/
	
	/*
	// IN C++14, NOW ALLOWED WITH THE HELP OF MOVE AS WELL, WHERE 'x' IS AN ARBITRARY ENTITY
	auto lm = [x=move(obj)]()
	{
		cout << "inside lambda" << endl;
		x->print();
	};
	lm();
	*/
	
	// IN C++14, NOW ALLOWED WITH THE HELP OF MOVE AS WELL, WHERE 'x' IS AN ARBITRARY ENTITY
	[x = move(obj)]()
	{
		cout << "inside lambda" << endl;
		x->print();
	}();
}