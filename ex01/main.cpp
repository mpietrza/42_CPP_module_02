/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:47:30 by mpietrza          #+#    #+#             */
/*   Updated: 2025/01/22 18:42:18 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed		a; //create a fixed point number using the default constructor
	Fixed const	b( 10 ); //create a fixed point number using the int constructor
	Fixed const	c( 42.42f ); //create a fixed point number using the float constructor
	Fixed const	d( b ); //create a fixed point number using the copy constructor
	a = Fixed( 1234.4321f ); //create a fixed point number using the float constructor and assign it to a
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
