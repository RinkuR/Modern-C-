#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
using namespace std;

class CA
{
	int a;
public:
	CA(int x = 0) :a(x) { cout << "CA constructor" << endl; }
	~CA() { cout << "CA destructor" << endl; }
	void print() { cout << "CA-print:" << a << endl; }
};


int main()
{
	vector<CA *> vect_ptr1;  //A vector of pointers
	//TRADITIONAL APPROACH
	vect_ptr1.push_back(new CA(10));
	vect_ptr1.push_back(new CA(20));
	vect_ptr1.push_back(new CA(30));
	vect_ptr1.push_back(new CA(40));
	vect_ptr1.push_back(new CA(50));

	vector<CA*>::iterator itr = vect_ptr1.begin();
	while (itr != vect_ptr1.end())
	{
		(*itr)->print();
		itr++;
	}
	//Now care should be taken to clean the HEAP 'int' instances
	itr = vect_ptr1.begin();
	while (itr != vect_ptr1.end())
	{
		delete *itr;
		itr++;
	}


	//***************MODERN APPROACH**************************
	//A vector of pointers
	vector<CA *> vect_ptr2{ new CA(10), new CA(20), new CA(30), new CA(40), new CA(50) };
	for (auto &x : vect_ptr2)
	{
		x->print();
	}
	for_each(vect_ptr2.begin(), vect_ptr2.end(),default_delete<CA>());
	return 0;
}
