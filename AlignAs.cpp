#include<iostream>
using namespace std;

class alignas(8) CA
{
	double a;
	int b;
	char c;
};

class alignas(32) CB
{
	double a;
	int b;
	char c;
};

void main()
{
	cout << "size of CA " << sizeof(CA) << endl;
	cout << "size of CB " << sizeof(CB) << endl;
}