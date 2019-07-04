#include<iostream>
#include<array>
using namespace std;

//C++11 feature, A constexpr function can only have a single executable statement

constexpr int Prod1(int x, int y) noexcept
{
	return x * y;
}

//C++14 feature, Can have more statements
constexpr int Prod2(int x, int y) noexcept
{
	int result{};
	if (x != 0)
	{
		if (y != 0)
		{
			result = x * y;
		}
	}
	return result;
}

int main()
{
	array<int, Prod1(2,3)> arr1;
	array<float, Prod2(4, 5)> arr2;
	cout << arr1.size() << endl;
	cout << arr2.size() << endl;
	return 0;
}