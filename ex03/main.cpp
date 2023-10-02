#include "Point.hpp"
#include "Fixed.hpp"

int main(void)
{
	Point A(1, 1);
	Point B(2, 5);
	Point C(5, 5);
	Point Pnt(C);

	if (bsp(A, B, C, Pnt) == true)
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Outside" << std::endl;
	return 0;
}
