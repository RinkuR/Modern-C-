#include<iostream>
using namespace std;
#include<iostream>
using namespace std;

class CA
{
public:
	CA(){ cout << __FUNCSIG__ << endl; }
	CA(const CA &x){ cout << __FUNCSIG__ << endl; }
	~CA(){ cout << __FUNCSIG__ << endl; }
};


//const CA f1()
//{
//	cout << __FUNCSIG__ << endl;
//	CA obj1;
//	return obj1;
//}
//
// CA f2()
//{
//	cout << __FUNCSIG__ << endl;
//	CA obj1;
//	return obj1;
//}
 /*CA& f3()
 {
	 cout << __FUNCSIG__ << endl;
	 CA obj1;
	 return obj1;
 }*/
 /*void fun(CA &x)
 {
	 cout << __FUNCSIG__ << endl;
 }
 void fun(CA &&x)
 {
	 cout << __FUNCSIG__ << endl;
 }
 void fun(const CA &x)
 {
	 cout << __FUNCSIG__ << endl;
 }
 void pf(CA x)
 {
	 cout << __FUNCSIG__ << endl;
 }*/
 void fun(int &&x)
 {
	 cout << __FUNCSIG__ << endl;
 }
 void fun(const int &x)
 {
	 cout << __FUNCSIG__ << endl;
 }
 const int g()
 {
	 return 100;
 }
 void main()
 {
	 //CA obj(f1());
	 //fun(f1());
	 //fun(100);
	 fun(g());
	 int a=10;
	 
	 fun(a);
	 //const CA obj1;
	 //fun(obj1);
	 
 }