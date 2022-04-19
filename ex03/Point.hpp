/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:19:37 by anasr             #+#    #+#             */
/*   Updated: 2022/04/19 23:05:45 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(const float f1, const float f2);
	Point(const Point& original);
	Point&	operator=(const Point& original);
	Fixed	sideLength(const Point& p1, const Point& p2);
	Fixed	areaOfTriangle(const Fixed& a, const Fixed& b, const Fixed& c);
	~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif