#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	_value = 0;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called\n";
	this->_value = value << _fbit_count;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called\n";
	this->_value = roundf(value * (1 << _fbit_count));
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called\n";
	_value = other.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const {
	return (_value);
}

float Fixed::toFloat(void) const {
	return ((float)_value / (1 << _fbit_count));
}

int Fixed::toInt(void) const {
	return (_value >> _fbit_count);
}

std::ostream& operator<<(std::ostream& file, const Fixed& value) {
	return(file << value.toFloat());
}
