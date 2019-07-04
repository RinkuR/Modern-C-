#include<iostream>
#include<chrono>
using namespace std;

void main()
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	// Some computations...
	end = std::chrono::system_clock::now();
	
	std::chrono::duration<double> elapsed_seconds = end - start;

}   