#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	_value = 0;
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

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called\n";
	return (_value);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	_value = raw;
}

