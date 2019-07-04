#include<iostream>
#include<array>
using namespace std;

int main()
{
	int val1;
	int val2 = 100;
	const int val3 = 100;
	//constexpr auto x1 = val1;   
	//constexpr auto x2 = val2;
	constexpr auto x3 = val3;
	array<int, val3> arr1;

	const auto x4 = val2;
	//array<int, x4> arr2;
}
