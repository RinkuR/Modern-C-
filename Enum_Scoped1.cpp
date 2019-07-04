#include<iostream>
using namespace std;

void main()
{
	enum class RANK  : short int   //underlying type - if specified shall be integral types only.
	{
		FIRST,
		SECOND,
		THIRD
	};

	//RANK obj = FIRST;
	RANK obj1 = RANK::FIRST;
	auto obj2 = RANK::SECOND;
	if (obj1 != obj2)
		cout << "not equal" << endl;
	else
		cout << "equal" << endl;
	
}