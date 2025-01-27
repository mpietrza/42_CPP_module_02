/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:52:04 by mpietrza          #+#    #+#             */
/*   Updated: 2025/01/27 16:38:16 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_fixedPointNumVal;
		static const int	_numOfFractBits = 8;
	public:
		Fixed( void );
		Fixed( const int integer);
		Fixed( const float floatingPoint);
		Fixed( const Fixed &other);
		Fixed &operator=(const Fixed &other);
		
		//comparison operators
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		
		//arythmetic operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		//pre-increment operator
		Fixed &operator++();
		//post-increment operator
		Fixed operator++(int);
		
		//pre-decrement operator
		Fixed &operator--();
		//post-decrement operator
		Fixed operator--(int);

		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;

		//overloaded member functions for min and max
		//2 fixed-point numbers, the smallest one
		static	Fixed &min(Fixed &a, Fixed &b);

		//2 constant fixed-point numbers, the smallest one
		static const	Fixed &min(const Fixed &a, const Fixed &b);

		//2 fixed-point numbers, the greatest one
		static	Fixed &max(Fixed &a, Fixed &b);

		//2 constant fixed-point numbers, the greatest one:
		static const	Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif
