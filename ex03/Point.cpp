/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:56:49 by mpietrza          #+#    #+#             */
/*   Updated: 2025/01/28 16:25:38 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//default constructor
Point::Point() : _x(0), _y(0) 
{}

//parametric constructor
Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y)
{}

//copy constructor
Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
	*this = other;//copy assignment operator
}

//copy assignment operator overload
  /*    
  * The copy assignment operator is called when an object is assigned to another object of the same type.
  * It checks for self-assignment and then assigns the value of the right-hand side object to the left-hand side object.
  * It then returns the left-hand side object.
  * The function is defined to return a reference to the object to allow for chaining of assignment operations.
  */
Point &Point::operator=(const Point &other)
{
	//as it is a const member variable, it cannot be changed
	//only added for the sake of completeness of the canonical form
	(void)other;
	return *this;
}

Point::~Point()
{}

Fixed Point::getX() const
{
	return _x;
}

Fixed Point::getY() const
{
	return _y;
}
