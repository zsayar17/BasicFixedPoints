#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const p)
{
	Fixed w1, w2;
	Fixed s1y = (c.getY() - a.getY()); //cy - ay
	Fixed s2y = (b.getY() - a.getY()); //by - ay
	Fixed s3y = (p.getY() - a.getY()); //py - ay
	Fixed s1x = (c.getX() - a.getX()); //cx - ax
	Fixed s2x = (b.getX() - a.getX()); //bx - ax
	Fixed s3x = (p.getX() - a.getX()); //px - ax


	w1 = (a.getX() * s1y + s3y * s1x - p.getX() * s1y) / (s2y * s1x - s2x * s1y);
	w2 = (p.getY() - a.getY() - w1 * s2y) / s1y;
	if (w1 <= 0 || w2 <= 0 || w1 + w2 >= 1) return (false);
	return (true);
}
