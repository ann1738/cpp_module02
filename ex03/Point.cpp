/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:22:34 by anasr             #+#    #+#             */
/*   Updated: 2022/04/20 15:37:52 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//default constructor

Point::Point(): x(Fixed(0)), y(Fixed(0)){ }

Point::Point(const float f1, const float f2): x(Fixed(f1)), y(Fixed(f2)){ }

Point::Point(const Point& original): x(Fixed(original.x)), y(Fixed(original.y))
{
	// std::cout << "Copy constructer is called\n";
}

Point::~Point()
{
	// std::cout << "Destructor is called\n";
}

Fixed	Point::sideLength(const Point& p1, const Point& p2)
{
	Fixed x_diff(Fixed(p1.x) - Fixed(p2.x));
	Fixed y_diff(Fixed(p1.y) - Fixed(p2.y));
	
	Fixed result((float)(sqrt(pow(x_diff.toFloat(), 2) + pow(y_diff.toFloat(), 2))));

	return (result);
}

Fixed	Point::areaOfTriangle(const Fixed& a, const Fixed& b, const Fixed& c)
{
	Fixed s(((Fixed)a + (Fixed)b + (Fixed)c) / 2);
	
	Fixed temp(s * (s - a) * (s - b) * (s - c));
	Fixed area((float)(sqrt(temp.toFloat())));

	return (area);
}

Fixed	Point::getX()
{
	return (this->x);
}

Fixed	Point::getY()
{
	return (this->y);
}

bool	Point::pointOnLine(const Point& point, const Point& a, const Point& b)
{
	//firstly, we need to find the line formula y = mx + b

	if ((((Point)a).getX() == ((Point)b).getX()))
	{
		if ((((Point)point).getX() == ((Point)a).getX()))
			return (true);
		return (false);
	}	
	Fixed m((((Point)a).getY() - ((Point)b).getY()) / (((Point)a).getX() - ((Point)b).getX()));
	Fixed y_intercept(((Point)a).getY() / (((Point)a).getX() * m));
	
	return (((Point)point).getY() == (((Point)point).getX() * m) + y_intercept ? true : false);
	
}

bool	Point::checkSameAsVertix(const Point& point, const Point& a)
{
	if (((Point)point).getX() == ((Point)a).getX() && ((Point)point).getY() == ((Point)a).getY())
		return (true);
	return (false);
}
