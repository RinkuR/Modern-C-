#include<iostream>
#include<memory>
using namespace std;

class CA :public enable_shared_from_this<CA>
{
public:
	CA() { cout << "CA constructor called" << endl; }
	~CA() { cout << "CA destructor called" << endl; }
	shared_ptr<CA> GetPtr()
	{
		return shared_from_this();  //return's shared_ptr<CA> instance
	}
};

class CB 
{
public:
	CB() { cout << "CB constructor called" << endl; }
	~CB() { cout << "CB destructor called" << endl; }
	shared_ptr<CB> GetPtr()
	{
		return shared_ptr<CB>(this);  //return's shared_ptr<CA> instance
	}
};
int main()
{
	auto ptr1 = make_shared<CA>();  // 'ptr1' is pointing to a valid resource
	auto ptr2(ptr1->GetPtr());
	cout << "Total shared count:" << ptr1.use_count() << endl;
	cout << "************************" << endl;
	shared_ptr<CA> ptr3;   // Here 'ptr3' is NOT pointing to any valid resource
	
	try
	{
		auto ptr4 = ptr3->GetPtr();  //A call to 'GetPtr' w.r.to 'ptr3' will now throw an exception
	}
	catch (const bad_weak_ptr &x)  //c++17 standard
	{
		cout << x.what() << endl;
	}
	catch (...)
	{
		cout << "Catch-any exception" << endl;
	}
	cout << "**************************************" << endl;
	auto pt1 = make_shared<CB>();
	auto pt2 = pt1->GetPtr();
	//Both 'pt1' and 'pt2' think they are owning distinct instances and not sharing
	cout << "pt1 shared count:" << pt1.use_count() << endl;
	cout << "pt2 shared count:" << pt2.use_count() << endl;
	//Thus leading to double delete.
}