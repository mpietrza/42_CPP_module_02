/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:46:21 by mpietrza          #+#    #+#             */
/*   Updated: 2025/01/28 16:20:45 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point();//default constructor
		Point(const Fixed  x, const Fixed  y);//parametric constructor
		Point(const Point &other);//copy constructor
		Point &operator=(const Point &other);//copy assignment operator overload
		~Point();//destructor

		Fixed getX() const;//getter for x
		Fixed getY() const;//getter for y
};

//function prototype for bsp.cpp
bool	bsp(const Point  a, const Point b, const Point c, const Point point);

#endif

