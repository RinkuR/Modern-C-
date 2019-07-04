#include<iostream>
using namespace std;

function<int(int)> f = [&f](int n)
{
return n <= 1 ? 1 : n * f(n - 1);
};

int main()
{  
   int x = f(4); 
   cout <<"x =" << x << endl;
   return 0;
}