#include <atomic>
#include <iostream>
using namespace std;

template <typename T>
T fetch_mult(std::atomic<T>& value, T mult) 
{
	T oldValue = value.load();
	value.store(oldValue += 10);
	return value.load();
}

int main() {
	std::atomic<int> myInt{ 5 };
	std::cout << myInt << std::endl;
	fetch_mult(myInt, 5);
	std::cout << myInt << std::endl;
}