/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:22:34 by anasr             #+#    #+#             */
/*   Updated: 2022/04/19 23:23:40 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//default constructor

Point::Point(): x(Fixed(0)), y(Fixed(0)){ }

Point::Point(const float f1, const float f2): x(Fixed(f1)), y(Fixed(f2)){ }

Point::Point(const Point& original): x(Fixed(original.x)), y(Fixed(original.y))
{
	std::cout << "Copy constructer is called\n";
}

Point::~Point()
{
	std::cout << "Destructor is called\n";
}

Fixed	Point::sideLength(const Point& p1, const Point& p2)
{
	Fixed x_sum(Fixed(p1.x) + Fixed(p2.x));
	Fixed y_sum(Fixed(p1.y) + Fixed(p2.y));
	
	Fixed result((float)(sqrt(pow(x_sum.toFloat(), 2) + pow(y_sum.toFloat(), 2))));

	return (result);
}

Fixed	Point::areaOfTriangle(const Fixed& a, const Fixed& b, const Fixed& c)
{
	Fixed s(((Fixed)a + (Fixed)b + (Fixed)c) / 2);
	
	Fixed temp(s * (s - a) * (s - b) * (s - c));
	Fixed area((float)(sqrt(temp.toFloat())));

	return (area);
}