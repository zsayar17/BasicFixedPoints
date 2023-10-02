#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::Point(Point& other) : x(other.getX()), y(other.getY())
{

}

Point& Point::operator=(Point& other)
{
	(void)other;
	return (*this);
}

Point::~Point(void)
{
}

Fixed Point::getX(void) const {
	return (this->x);
}

Fixed Point::getY(void) const {
	return (this->y);
}

