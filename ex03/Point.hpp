/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:19:37 by anasr             #+#    #+#             */
/*   Updated: 2022/05/22 19:52:43 by anasr            ###   ########.fr       */
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
	~Point();

	//additional useful functions
	Fixed	getX() const;
	Fixed	getY() const;
};

Fixed	crossProduct(const Point& A, const Point& B);
Point	getVector(const Point& A, const Point& B);
bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif