/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:40:59 by anasr             #+#    #+#             */
/*   Updated: 2022/04/18 11:26:54 by ann              ###   ########.fr       */
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
	fixedPtValue <<= fracBits;
}

Fixed::Fixed(const float input)
{
	std::cout << "Float constructor called\n";
	fixedPtValue = roundf(input * (float)(1 << fracBits));
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
	return (fixedPtValue >> fracBits);
}

float Fixed::toFloat(void) const
{
	return ((float)fixedPtValue / (float)(1 << fracBits));
}

//insertion operator "<<" overloading

std::ostream& operator<<(std::ostream& console_out, const Fixed& current_fixed)
{
	console_out << current_fixed.toFloat();
	return (console_out);
}

// arithmetic operators
Fixed& Fixed::operator+(const Fixed& other_f)
{
	Fixed result(*this);
	// Fixed result;
	result.fixedPtValue = this->fixedPtValue + other_f.fixedPtValue;
	return ((Fixed &)result);
}

Fixed& Fixed::operator-(const Fixed& other_f)
{
	Fixed result(*this);
	// Fixed result;
	result.fixedPtValue = this->fixedPtValue + other_f.fixedPtValue;
	return ((Fixed &)result);
}

Fixed& Fixed::operator*(const Fixed& other_f)
{
	Fixed result(*this);
	// Fixed result;
	result.fixedPtValue = (int)((((long long)this->fixedPtValue) * ((long long)other_f.fixedPtValue)) >> fracBits);
	return ((Fixed &)result);
}

Fixed& Fixed::operator/(const Fixed& other_f)
{
	Fixed result(*this);
	result.fixedPtValue = (int)(((long long)(this->fixedPtValue) << fracBits) / other_f.fixedPtValue);
	return ((Fixed &)result);
}

//increment/decrement

//pre-increment
Fixed& Fixed::operator++(void)
{
	this->fixedPtValue += 1;
	return (*this);
}

//post-increment
Fixed& Fixed::operator++(int i)
{
	(void)i;
	Fixed temp = *this;
	++(this->fixedPtValue);
	
	return (temp);
}
Fixed& Fixed::operator--(void)
{
	this->fixedPtValue -= 1;
	return (*this);
}
