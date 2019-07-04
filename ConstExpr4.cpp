#include<iostream>
using namespace std;

class Point
{
private:
	double x, y;
public:
	constexpr Point(double a, double b) noexcept :x(a), y(b) { }
	constexpr double Get_x() const noexcept  { return x; }
	constexpr double Get_y() const noexcept { return y; }
	//Not allowed in C++11, but ok now in C++14
	constexpr void setX(double newX) noexcept { x = newX; }
	constexpr void setY(double newY) noexcept { y = newY; }
};

constexpr Point midpoint(const Point& p1, const Point& p2) noexcept
{
	return { (p1.Get_x() + p2.Get_y()) / 2, // call constexpr
	(p1.Get_x() + p2.Get_y()) / 2 }; // member funcs
}
int main()
{
	constexpr Point p1(12.34, 67.87);
	constexpr Point p2(56.32, 98.47);

	constexpr auto mid = midpoint(p1, p2);
	return 0;
}