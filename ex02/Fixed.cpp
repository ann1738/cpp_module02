/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:40:59 by anasr             #+#    #+#             */
/*   Updated: 2022/05/20 18:56:54 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructor

Fixed::Fixed()
{
	// std::cout << "Default constructor called\n";
	fixedPtValue = 0;
}

//Copy constructor

Fixed::Fixed(const Fixed& original)
{
	// std::cout << "Copy constructer is called\n";
	this->fixedPtValue = original.fixedPtValue;
}

//Assignment operator overloading

Fixed& Fixed::operator=(const Fixed& original)
{
	// std::cout << "Copy assignment operator called\n";
	this->fixedPtValue = original.fixedPtValue;
	return (*this);
}

//Destructor

Fixed::~Fixed()
{
	// std::cout << "Destructor called\n";
}

//Additional constructors

Fixed::Fixed(const int input)
{
	// std::cout << "Int constructor called\n";
	fixedPtValue = input;
	fixedPtValue <<= fracBits;
}

Fixed::Fixed(const float input)
{
	// std::cout << "Float constructor called\n";
	fixedPtValue = (input * (float)(1 << fracBits));
}

//Methods from ex00

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called\n";
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

//comparison operators
bool Fixed::operator>(const Fixed& other_f)
{
	return ((this->fixedPtValue > other_f.fixedPtValue) ? true : false);
}

bool Fixed::operator>=(const Fixed& other_f)
{
	return ((this->fixedPtValue >= other_f.fixedPtValue) ? true : false);
}

bool Fixed::operator<(const Fixed& other_f)
{
	return ((this->fixedPtValue < other_f.fixedPtValue) ? true : false);
}

bool Fixed::operator<=(const Fixed& other_f)
{
	return ((this->fixedPtValue <= other_f.fixedPtValue) ? true : false);
}

bool Fixed::operator==(const Fixed& other_f)
{
	return ((this->fixedPtValue == other_f.fixedPtValue) ? true : false);
}

bool Fixed::operator!=(const Fixed& other_f)
{
	return ((this->fixedPtValue != other_f.fixedPtValue) ? true : false);
}

// arithmetic operators

Fixed Fixed::operator+(const Fixed& other_f)
{
	Fixed result;
	result.fixedPtValue = this->fixedPtValue + other_f.fixedPtValue;

	return (result);
}

Fixed Fixed::operator-(const Fixed& other_f)
{
	Fixed result;
	result.fixedPtValue = this->fixedPtValue - other_f.fixedPtValue;

	return (result);
}

Fixed Fixed::operator*(const Fixed& other_f)
{
	Fixed result;
	result.fixedPtValue = (int)((((long long)this->fixedPtValue) * ((long long)other_f.fixedPtValue))\
								>> fracBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed& other_f)
{
	Fixed result;
	result.fixedPtValue = (int)(((long long)(this->fixedPtValue) << fracBits) / other_f.fixedPtValue);
	return (result);
}

//increment/decrement

//pre-increment
Fixed& Fixed::operator++(void)
{
	this->fixedPtValue += 1;
	return (*this);
}

//post-increment
Fixed Fixed::operator++(int i)
{
	(void)i;
	Fixed temp = *this;
	++(this->fixedPtValue);
	
	return (temp);
}

//pre-decrement
Fixed& Fixed::operator--(void)
{
	this->fixedPtValue -= 1;
	return (*this);
}
//post-decrement
Fixed Fixed::operator--(int i)
{
	(void)i;
	Fixed temp = *this;
	--(this->fixedPtValue);
	
	return (temp);
}

//static member functions
Fixed& Fixed::min(Fixed &f1, Fixed &f2)
{
	return ((f1.fixedPtValue <= f2.fixedPtValue) ? f1 : f2);
}

Fixed& Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return ((f1.fixedPtValue <= f2.fixedPtValue) ? (Fixed&)f1 : (Fixed&)f2);
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2)
{
	return ((f1.fixedPtValue >= f2.fixedPtValue) ? f1 : f2);
}

Fixed& Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return ((f1.fixedPtValue >= f2.fixedPtValue) ? (Fixed&)f1 : (Fixed&)f2);
}
