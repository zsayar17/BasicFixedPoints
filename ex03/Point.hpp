#pragma once

#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
#include "Fixed.hpp"


class Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point(void);
		Point(const float x, const float y);
		Point(Point& other);
		~Point(void);
		Point& operator=(Point& other);

		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
