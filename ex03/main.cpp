/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:47:30 by mpietrza          #+#    #+#             */
/*   Updated: 2025/01/28 15:37:51 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"


void testPoint(Point const &a, Point const &b, Point const &c, Point const &point) 
{
	std::cout << "Point (" << point.getX() << ", " << point.getY() << ") inside triangle: " 
			  << (bsp(a, b, c, point) ? "yes" : "no") << std::endl;
}

int main() {
	Point a(Fixed(0), Fixed(0));
	Point b(Fixed(10), Fixed(0));
	Point c(Fixed(0), Fixed(10));

	// Points inside the triangle
	Point point1(Fixed(2), Fixed(5));
	Point point2(Fixed(1), Fixed(1));
	Point point3(Fixed(3), Fixed(2));

	// Points outside the triangle
	Point point4(Fixed(10), Fixed(10));
	Point point5(Fixed(-1), Fixed(-1));
	Point point6(Fixed(10), Fixed(5));

	// Points on the edges of the triangle
	Point point7(Fixed(0), Fixed(0));
	Point point8(Fixed(5), Fixed(0));
	Point point9(Fixed(0), Fixed(5));

	std::cout << "Triangle vertices: " << std::endl;
	std::cout << "A: (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	std::cout << "B: (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	std::cout << "C: (" << c.getX() << ", " << c.getY() << ")\n" << std::endl;
	
	std::cout << "Testing points inside the triangle:" << std::endl;
	testPoint(a, b, c, point1);
	testPoint(a, b, c, point2);
	testPoint(a, b, c, point3);

	std::cout << "\nTesting points outside the triangle:" << std::endl;
	testPoint(a, b, c, point4);
	testPoint(a, b, c, point5);
	testPoint(a, b, c, point6);

	std::cout << "\nTesting points on the edges of the triangle:" << std::endl;
	testPoint(a, b, c, point7);
	testPoint(a, b, c, point8);
	testPoint(a, b, c, point9);

	return 0;
}