#include<iostream>
using namespace std;

template<typename...TAIL> class CA
{
public:

};
template<typename HEAD, typename ... TAIL> class CA<HEAD, TAIL...> : CA<TAIL...>
{
private:
	HEAD data;
public:

	CA(HEAD h, TAIL... args) :CA<TAIL... >(args...), data(h)
	{
		cout << "No. of elements left further ..." << sizeof...(args) << endl;
		cout << "data " << h << endl;
	}

};


//***************************
void main()
{
	CA<int, float, double> obj1(10,12.34f, 56.12);
	//CA<int, float, int, char> obj1(10, 12.34f, 56, 'c');
}