#include <atomic>
#include <iostream>
using namespace std;

int val1 = 4;
int val2 = 6;

template <typename T>void fetch_mult1(std::atomic<T>& value, T mult)
{
	T oldValue = value.load();
	cout << "old Value:" << oldValue << endl;
	while (value.compare_exchange_strong(oldValue, mult));
	cout << "old Value:" << oldValue << endl;
	cout << "new value:" << value.load() << endl;
}
template <typename T>void fetch_mult2(std::atomic<T>& value, T mult)
{
	T oldValue = value.load()+10;
	cout << "old Value:" << oldValue << endl;
	cout << "new value:" << value.load() << endl;
	while (value.compare_exchange_strong(oldValue, mult));
	cout << "old Value:" << oldValue << endl;
	cout << "new value:" << value.load() << endl;
}
int main() {
	atomic<int> myInt{ 5 };
	cout << myInt << endl;
	fetch_mult1(myInt, 6);
	cout << "----------------" << endl;
	atomic<int> myInt2{ 10 };
	cout << myInt2 << endl;
	fetch_mult2(myInt2, 8);
}