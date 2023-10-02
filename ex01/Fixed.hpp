#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		static const int _fbit_count = 8;

		int	_value;
	public:
		Fixed();//default constructure;
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other); //copy Constructure;
		Fixed& operator=(const Fixed& other);//copy assignment;
		~Fixed();//distructure;

		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
};

std::ostream& operator<<(std::ostream& file, const Fixed& value);

#endif
