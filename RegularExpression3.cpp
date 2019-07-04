#include<iostream>
#include<regex>
#include<string>
using namespace std;

void main()
{
	string input;
	regex integer("\\+?[[:digit:]]+"); //single or multiple digits, but positive numbers only
	cout << "enter any single digit number, 'q' to quit" << endl;
	while (true)
	{
		cin >> input;
		if (!cin) break;
		if (input == "q")
			break;
		if (regex_match(input, integer))
			cout << "integer" << endl;
		else
			cout << "invalid input" << endl;
	}
}