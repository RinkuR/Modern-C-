#include<iostream>
using namespace std;

template<typename T> class U_Ptr
{
private:
	T *pointee;
public:
	U_Ptr() :pointee(nullptr) { }
	U_Ptr(U_Ptr &&x)
	{
		cout << "move constructor" << endl;
		this->pointee = move(x.pointee);
	}
	U_Ptr& operator =(U_Ptr &&x)
	{
		cout << "move assignment" << endl;
		this->pointee = move(x.pointee);
		return *this;
	}
	void operator =(T *p)
	{
		this->pointee = p;
	}
	//***********************
	U_Ptr(const U_Ptr &x) = delete;
	U_Ptr& operator =(const U_Ptr &x) = delete;
	//*************************
	U_Ptr(T *type) { pointee = type; }
	~U_Ptr()
	{
		if (pointee != nullptr)
		{
			delete pointee;
		}
	}
	T& operator *() { return *pointee; }
	T* operator ->() { return pointee; }
};

class CA
{
private:
	int a, b;
public:
	CA(int x = 0, int y = 0) :a(x), b(y) { cout << "CA constructor" << endl; }
	void print() { cout << "CA-print, a=" << a << ",b=" << b << endl; }
	~CA() { cout << "CA destructor" << endl; }
};
//---------------------------------
U_Ptr<CA> Fun()
{
	U_Ptr<CA> obj1;
	//...
	return obj1;
}
void main()
{
	U_Ptr<CA> p1(new CA);
	//p1= new CA;
	p1->print();
	//***********************
	U_Ptr<CA> p2;
	p2 = move(p1);
	p2->print();
	//p1->print();
	//************************
	U_Ptr<CA> p3(Fun());

}