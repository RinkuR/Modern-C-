#include<iostream>
#include<array>
using namespace std;

template<typename T, size_t N> constexpr size_t ArrSize(T(&)[N]) noexcept
{
	return N;
}

int main()
{
	int arr1[] = { 1,2,3,4,5 };
	ArrSize(arr1);

	array<int, ArrSize(arr1)> MyNewArray;

	return 0;
}