/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:21:02 by mpietrza          #+#    #+#             */
/*   Updated: 2025/01/28 16:31:52 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief Calculate the sign of the area of a triangle
 * 
 * @param p1 First point of the triangle
 * @param p2 Second point of the triangle
 * @param p3 Third point of the triangle
 * 
 * @return The sign of the area of the triangle
 * 
 * @note The area of a triangle is calculated as:
 * (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y)
 * The sign of the area is calculated by checking if the result is positive or negative
 * If the result is positive, the sign is positive
 * If the result is negative, the sign is negative
 * If the result is zero, the sign is zero
 * The sign is used to determine if a point is inside a triangle
 * If the sign is positive, the point is outside the triangle
 * If the sign is negative, the point is inside the triangle
 * If the sign is zero, the point is on the edge of the triangle
 * The function is defined as a static member function to allow for the calling of the function without an object of the class
 * The function is defined outside of the class definition to allow for the definition of the function after the definition of the Fixed class
 * The function is defined as a const member function to allow for the calling of the function on const objects
 * 
 */
static Fixed	sign(Point const &p1, Point const &p2, Point const &p3)
{
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

/**
 * @brief Check if a point is inside a triangle
 * 
 * @param a First point of the triangle
 * @param b Second point of the triangle
 * @param c Third point of the triangle
 * @param point Point to check
 * the boolean variable `has_neg` is set to `true` if any of the values `d1`, `d2`, or `d3` are negative, 
 * indicating that the point lies on the opposite side of one of the triangle's edges. Similarly, `has_pos` 
 * is set to `true` if any of the values `d1`, `d2`, or `d3` are positive, indicating that the point lies 
 * on the same side of one of the triangle's edges.
 * These boolean variables are used to determine if the point lies inside the triangle. 
 * If both `has_neg` and `has_pos` are `true`, the point lies outside the triangle. If either `has_neg` 
 * or `has_pos` is `false`, the point lies inside the triangle.
 * @return true if the point is inside the triangle, false otherwise
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1, d2, d3;
	bool has_neg, has_pos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos) && d1 != 0 && d2 != 0 && d3 != 0;
}

