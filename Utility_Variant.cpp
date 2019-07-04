#include <iostream>
#include <variant>
#include<string>

using namespace std;
struct SampleVisitor
{
	void operator()(const int &i) const { cout << "int: " << i << endl; }
	void operator()(const float& f) const { cout << "float: " << f << endl; }
};

int main()
{
	variant<int, float> intOrFloat;
	static_assert(variant_size_v<decltype(intOrFloat)> == 2, "Parameter types are few/excess");

	// default initialized to the first alternative, should be 0
	std::visit(SampleVisitor(), intOrFloat);

	//intOrFloat = string("hello");   //ERROR

	// index will show the currently used 'type'
	cout << "Active index = " << intOrFloat.index() << endl;
	intOrFloat = 100.0f;
	cout << "Active index = " << intOrFloat.index() << endl;

	// visit:
	visit(SampleVisitor(), intOrFloat);
	intOrFloat = 10;
	visit(SampleVisitor(), intOrFloat);
	
	return 0;
}