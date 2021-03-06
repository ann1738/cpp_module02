/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:22:34 by anasr             #+#    #+#             */
/*   Updated: 2022/05/23 11:02:18 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//orthodox requirements

Point::Point(): x(Fixed(0)), y(Fixed(0)){ }

Point::Point(const float f1, const float f2): x(Fixed(f1)), y(Fixed(f2)){ }

Point::Point(const Point& original): x(Fixed(original.x)), y(Fixed(original.y))
{
	// std::cout << "Copy constructer is called\n";
}

Point& Point::operator=(const Point& original)
{
	// std::cout << "Copy assignment operator is called\n";
	if (this != &original)
	{
		const_cast<Fixed&>(this->x) = original.x;
		const_cast<Fixed&>(this->y) = original.y;
	}
	return (*this);
}

Point::~Point()
{
	// std::cout << "Destructor is called\n";
}

//additional helpful memeber functions

Fixed	Point::getX() const
{
	return (this->x);
}

Fixed	Point::getY() const
{
	return (this->y);
}
