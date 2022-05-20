/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:40:59 by anasr             #+#    #+#             */
/*   Updated: 2022/05/20 18:56:58 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructor

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	fixedPtValue = 0;
}

//Copy constructor

Fixed::Fixed(const Fixed& original)
{
	std::cout << "Copy constructer is called\n";
	this->fixedPtValue = original.fixedPtValue;
}

//Assignment operator overloading

Fixed& Fixed::operator=(const Fixed& original)
{
	std::cout << "Copy assignment operator called\n";
	this->fixedPtValue = original.fixedPtValue;
	return (*this);
}

//Destructor

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

//Additional constructors

Fixed::Fixed(const int input)
{
	std::cout << "Int constructor called\n";
	fixedPtValue = input;
	fixedPtValue <<= 8;
}

Fixed::Fixed(const float input)
{
	std::cout << "Float constructor called\n";
	fixedPtValue = (input * (float)(1 << 8));
}

//Methods from ex00

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (fixedPtValue);
}

void Fixed::setRawBits(int const raw)
{
	fixedPtValue = raw;
}

//New methods

int Fixed::toInt(void) const
{
	return (fixedPtValue >> 8);
}

float Fixed::toFloat(void) const
{
	return ((float)fixedPtValue / (float)(1 << 8));
}

//insertion operator "<<" overloading

std::ostream& operator<<(std::ostream& console_out, const Fixed& current_fixed)
{
	console_out << current_fixed.toFloat();
	return (console_out);
}
