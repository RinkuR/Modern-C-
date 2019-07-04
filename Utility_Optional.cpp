#include <optional>
#include <iostream>
#include <string>
using namespace std;

optional<int> GetInt(int r)
{
	if (r % 2 == 0)
		return r / 2;
	return {};
}
void ShowOptionalInt(const optional<int>& oi)
{
	if (oi)
		cout << "int ok: " << *oi << endl;
	else
		cout << "bad int..." << endl;
}

int main()
{
	cout << "size of objects..." << endl;
	cout <<"int:" <<sizeof(int) << ", " <<"optional<int>:" <<sizeof(optional<int>) << endl;
	cout << "double:" << sizeof(double) << ", " << "optional<double>:" << sizeof(optional<double>) << endl;
	cout << "string:" << sizeof(string) << ", " << "optional<string>:" << sizeof(optional<string>) << endl;
	
	cout << "******************" << endl;
	auto oi = GetInt(10);
	ShowOptionalInt(oi);
	auto oi2 = GetInt(11);
	ShowOptionalInt(oi2);

	return 0;
}