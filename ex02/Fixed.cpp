/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:46:31 by mpietrza          #+#    #+#             */
/*   Updated: 2025/01/24 16:42:31 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <cstdint> //For int64_t used in multiplication and division

//Default constructor:
Fixed::Fixed( void ) : _fixedPointNumVal(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//Parametric constructor - int:
Fixed::Fixed( const int integer ) : _fixedPointNumVal(integer << _numOfFractBits)
{
	std::cout << "Int constructor called" << std::endl;
}

//Parametric constructor - float:
Fixed::Fixed( const float floatingPoint ) 
{
	_fixedPointNumVal = roundf(floatingPoint * (1 << _numOfFractBits));
	std::cout << "Float constructor called" << std::endl;
}

//Copy constructor:
Fixed::Fixed( const Fixed &other)
{
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

//Copy assignment operator overload:
/**
 * @brief Assignment operator overload
 * 
 * @param other 
 * @return Fixed& 
 * 
 * This function is called when an object is assigned to another object of the same type.
 * It checks for self-assignment and then assigns the value of the right-hand side object to the left-hand side object.
 * It then returns the left-hand side object.
 * The function is defined to return a reference to the object to allow for chaining of assignment operations.
 */
Fixed	&Fixed::operator=(const Fixed &other)
{
	if (this != &other) //Check for self-assignment
		this->_fixedPointNumVal = other._fixedPointNumVal;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

//comparison operators

bool	operator>(const Fixed &other) const
{
	return this->_fixedPointNumVal > other._fixedPointNumVal;
}

bool	operator<(const Fixed &other) const
{
	return this->_fixedPointNumVal < other._fixedPointNumVal;
}

bool	operator>=(const fixed &other) const
{
	return this->_fixedPointNumVal >= other._fixedPointNumVal;
}

bool	operator<=(const fixed &other) const
{
	return this->_fixedPointNumVal <= other._fixedPointNumVal;
}

bool	operator==(const fixed &other) const
{
	return this->_fixedPointNumVal == other._fixedPointNumVal;
}

bool	operator!=(const fixed &other) const
{
	return this->_fixedPoinNumVal != other._fixedPointNumVal;
}

//arythmetic operators
Fixed operator+(const Fixed &other) const
{
	Fixed result;
	result._fixedPointNumVal = this->_fixedPointNumVal + other._fixedPointNumVal;
	return result;
}

Fixed operator-(const Fixed &other) const
{
	Fixed result;
	result._fixedPointNumVal = this->_fixedPointNumVal - other._fixedPointNumVal;
	return result;
}

Fixed operator*(const Fixed &other) const
{
	Fixed result;
	int64_t temp = static_cast<int64_t>(this->_fixedPointNumVal) * static_cast<int64_t>(other->_fixedPointNumVal);
	result._fixedPointNumVal = static_cast<int>(temp >> _numOfFractBits);
	return result;
}

Fixed operator/(const Fixed &other) const
{
	Fixed result;
	int64_t temp = static_cast<int64_t>(this->_fixedPointNumVal) << _numOfFractBits / static_cast<int64_t>(other->_fixedPointNumVal);
	result._fixedPointNumVal = this->_fixedPointNumVal - other._fixedPointNumVal;
	return result;
}

//pre-increment operator
Fixed &operator++()
{
	this->_fixedPointNumVal += 1; //increment by the smallest representable value (1 bit)
	return *this;
}

//post-increment operator
Fixed operator++(int)
{
	Fixed temp = *this; // a copy
	this->_fixedPointNumVal += 1; //increment by the smallest representable value (1bit)
	return temp; // return the copy
}

//pre-decrement operator
Fixed &operator--()
{
	this->_fixedPointNumVal -= 1; //increment by the smallest representable value (1 bit)
	return *this;
}

//post-decrement operator
Fixed operator--(int)
{
	Fixed temp = *this; // a copy
	this->_fixedPointNumVal -= 1; //increment by the smallest representable value (1bit)
	return temp; // return the copy
}

//Destructor
Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointNumVal;
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixedPointNumVal = raw;
}

/**
 * @brief Convert the fixed point value to a floating point value
 * 
 * @return float
 * 
 * This function converts the fixed point value to a floating point value.
 * It does this by dividing the fixed point value by 2 raised to the power of the number of fractional bits.
 * The function returns the floating point value.
 * The function is defined as a const member function to allow for the calling of the function on const objects.
 * The function is defined outside of the class definition to allow for the definition of the function after the definition of the Fixed class.
 */
float	Fixed::toFloat(void) const
{
	return static_cast<float>(this->_fixedPointNumVal) / (1 << _numOfFractBits);
}

/**
 * @brief Convert the fixed point value to an integer value
 * 
 * @return int
 * 
 * This function converts the fixed point value to an integer value.
 * It does this by shifting the fixed point value to the right by the number of fractional bits.
 * The function returns the integer value.
 * The function is defined as a const member function to allow for the calling of the function on const objects.
 */
int	Fixed::toInt(void) const
{
	return this->_fixedPointNumVal >> _numOfFractBits;
}

/**
 * @brief Overload of the << operator
 * 
 * @param std::ostream &out - a reference to an output stream object from the Standard Library
 * @param const Fixed &fixed - a reference to a constant object of the Fixed class 
 * @return std::ostream& - a reference to an output stream object from the Standard Library 
 * 
 * This function is called when the << operator is used with an object of the Fixed class.
 * It outputs the value of the object to the output stream.
 * The function is defined to return a reference to the output stream to allow for chaining of output operations.
 * The function outputs the value of the object to the output stream by calling the toFloat() member function of the object.
 */
std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

