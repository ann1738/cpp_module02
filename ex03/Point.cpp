/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:22:34 by anasr             #+#    #+#             */
/*   Updated: 2022/04/18 13:31:01 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//default constructor

Point::Point(): x(Fixed(0)), y(Fixed(0)){ }

Point::Point(const float f1, const float f2): x(Fixed(f1)), y(Fixed(f2)){ }

Point(const Point& original): x(Fixed(original.x)), y(Fixed(original.y))
{
	std::cout << "Copy constructer is called\n";
}

Point::~Point()
{
	std::cout << "Destructor is called\n";
}
