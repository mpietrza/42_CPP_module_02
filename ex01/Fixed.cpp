/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:46:31 by mpietrza          #+#    #+#             */
/*   Updated: 2025/01/22 18:55:34 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

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
Fixed	&Fixed::operator=(const Fixed &other)
{
	if (this != &other) //Check for self-assignment
		this->_fixedPointNumVal = other._fixedPointNumVal;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
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

float	Fixed::toFloat(void) const
{
	return static_cast<float>(this->_fixedPointNumVal) / (1 << _numOfFractBits);
}

int	Fixed::toInt(void) const
{
	return this->_fixedPointNumVal >> _numOfFractBits;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

