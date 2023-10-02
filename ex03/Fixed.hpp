#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		static const int _fbit_count = 8;

		int	_value;

		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int value);
	public:
		Fixed();//default constructure;
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other); //copy Constructure;
		Fixed& operator=(const Fixed& other);//copy assignment;
		~Fixed();//distructure;

		bool operator<(const Fixed& other) const;
		bool operator>(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		Fixed operator/(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator+(const Fixed& other) const;
		Fixed& operator++(void);
		Fixed& operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
		static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
		static Fixed& max(Fixed& fixed1, Fixed& fixed2);
		static Fixed& min(Fixed& fixed1, Fixed& fixed2);
		float toFloat(void) const;
};

std::ostream& operator<<(std::ostream& file, const Fixed& value);

#endif
