#include <string>
#include <iostream>
#include <any>
using namespace std;

/*  NOTE:
- 'any' does not facilitate conversion to other types on the value held by him.
- 'any' object might be empty.
- 'any' shouldn’t use any dynamically allocated memory, but it’s not guaranteed by the spec.
*/

int main()
{
	auto a = any(12);
	// set any value:
	a = string("Hello!");
	cout << any_cast<string>(a) << endl;   //OK
	a = 16;
	// we can read it as int
	cout << any_cast<int>(a) << endl;   //will throw exception
	// but not as string:
	try
	{
		cout << any_cast<string>(a) << endl;
	}
	catch (const bad_any_cast& e)
	{
		cout << e.what() << endl;
	}
	// reset and check if it contains any value:
	a.reset();
	if (!a.has_value())
	{
		cout << "a is empty!" << endl;
	}
}