#include "Fixed.hpp"

Fixed::Fixed() {
	_value = 0;
}

Fixed::Fixed(const int value) {
	setRawBits(value << _fbit_count);
}

Fixed::Fixed(const float value) {
	setRawBits(roundf(value * (1 << _fbit_count)));
}


Fixed& Fixed::operator=(const Fixed& other) {
	setRawBits(other.getRawBits());
	return (*this);
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::~Fixed() {

}

void Fixed::setRawBits(int value) {
	this->_value = value;
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

bool Fixed::operator<(const Fixed& other) const {
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>(const Fixed& other) const {
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const {
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const {
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const {
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const {
	return (this->getRawBits() != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& other) const {
	Fixed new_fixed;

	new_fixed.setRawBits(this->getRawBits() + other.getRawBits());
	return (new_fixed);
}

Fixed	Fixed::operator-(const Fixed& other) const {
	Fixed new_fixed;

	new_fixed.setRawBits(this->getRawBits() - other.getRawBits());
	return (new_fixed);
}

Fixed	Fixed::operator/(const Fixed& other) const {
	Fixed new_fixed;
	float	result;

	result = this->toFloat() / other.toFloat();
	new_fixed.setRawBits(roundf(result * (1 << _fbit_count)));
	return (new_fixed);
}

Fixed	Fixed::operator*(const Fixed& other) const {
	Fixed new_fixed;
	float	result;

	result = this->toFloat() * other.toFloat();
	new_fixed.setRawBits(roundf(result * (1 << _fbit_count)));
	return (new_fixed);
}

Fixed& Fixed::operator++(void) {
	this->_value += (1 << _fbit_count);
	return (*this);
}

Fixed Fixed::operator++(int){
	Fixed new_fixed;

	new_fixed = *this;
	*this = *this + 1;
	return (new_fixed);
}

Fixed Fixed::operator--(int){
	Fixed new_fixed;

	new_fixed = *this;
	*this = *this - 1;
	return (new_fixed);
}


Fixed& Fixed::operator--(void) {
	this->_value -= (1 << _fbit_count);
	return (*this);
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2) {
	return (fixed1 > fixed2) ? fixed1 : fixed2;
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2) {
	return (fixed1 < fixed2) ? fixed1 : fixed2;
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2) {
	return (fixed1 > fixed2) ? fixed1 : fixed2;
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2) {
	return (fixed1 < fixed2) ? fixed1 : fixed2;
}


std::ostream& operator<<(std::ostream& file, const Fixed& value) {
	return(file << value.toFloat());
}
