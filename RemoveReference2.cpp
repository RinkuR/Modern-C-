#include<iostream>
#include<type_traits>
using namespace std;

class CA
{
private:
	int a, b;
public:
	explicit CA(int x = 0, int y = 0) :a(x), b(y) { cout << "CA default constructor" << endl; }
	CA(const CA &x) :a(x.a), b(x.b) { cout << "CA copy constr." << endl; }
	CA(CA&& x) :a(move(x.a)), b(move(x.b)) { cout << "CA move copy constr." << endl; }
	CA& operator =(const CA &x)
	{
		cout << "CA operator =" << endl;
		this->a = x.a;
		this->b = x.b;
		return *this;
	}
	void print() const { cout << "a = " << a << ",b = " << b << endl; }
	~CA() { cout << "CA destructor" << endl; }
};
//*****************



void main()
{
	
	const CA obj1(10, 20);
	//CA obj2 = obj1;
	//CA obj2 = move(obj1);  //Don't use a 'move' on a const object on RHS, as it will
	                            //not call MOVE COPY CONSTRUCTOR
	CA obj2 = (remove_reference_t<CA>&&)obj1;   //SUCCEEDS IN MOVE COPY CONSTR. CALL
	obj1.print();
	cout << "---------------" << endl;
	CA obj3(20, 30);
	//CA obj4 = obj3;
	CA obj4 = move(obj3);   // A call to 'move' on a non-const object on RHS is fine
	                         //AS IT CALLS MOVE COPY CONSTR;
}
