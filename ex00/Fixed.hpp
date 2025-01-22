/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:52:04 by mpietrza          #+#    #+#             */
/*   Updated: 2025/01/22 17:34:35 by mpietrza         ###   ########.fr       */
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
		Fixed( const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
