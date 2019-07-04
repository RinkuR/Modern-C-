#include <type_traits>  
#include<iostream>
using namespace std;
template <typename T> T copy_object(T& obj) noexcept(is_pod<T>::value)
{
	cout << "function called" << endl;
	return obj;
}
class CA {  };
void main()
{
	try
	{
		int y = 100;
		//auto x = copy_object(y);
		CA x = copy_object(CA());
	}
	catch (...)
	{
		cout << "exception handled" << endl;
	}
}