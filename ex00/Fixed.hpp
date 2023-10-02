#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>

class Fixed
{
	private:
		static const int _fbit_count = 8;

		int	_value;
	public:
		Fixed();//default constructure;
		Fixed(const Fixed& other); //copy Constructure;
		Fixed& operator=(const Fixed& other);//copy assignment;
		~Fixed();//distructure;

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
