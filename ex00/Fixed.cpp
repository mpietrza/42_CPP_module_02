/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:46:31 by mpietrza          #+#    #+#             */
/*   Updated: 2025/01/22 17:35:46 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default constructor:
Fixed::Fixed( void ) : _fixedPointNumVal(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//Copy constructor:
Fixed::Fixed( const Fixed &other)
{
	this->_fixedPointNumVal = other._fixedPointNumVal;
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

