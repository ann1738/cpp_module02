/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:40:59 by anasr             #+#    #+#             */
/*   Updated: 2022/05/23 14:15:29 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Orthodox Canonical Form Requirements */

// default constructor
Fixed::Fixed()
{
	// std::cout << "Default constructor called\n";
	fixedPtValue = 0;
}

// copy constructor
Fixed::Fixed(const Fixed& original)
{
	// std::cout << "Copy constructer is called\n";
	this->fixedPtValue = original.fixedPtValue;
}

// copy assignment operator overloading
Fixed& Fixed::operator=(const Fixed& original)
{
	// std::cout << "Copy assignment operator called\n";
	if (this != &original)
		this->fixedPtValue = original.fixedPtValue;
	return (*this);
}

// destructor
Fixed::~Fixed()
{
	// std::cout << "Destructor called\n";
}

/* Additional Constructors */

Fixed::Fixed(const int input)
{
	// std::cout << "Int constructor called\n";
	fixedPtValue = input << fracBits;
}

Fixed::Fixed(const float input)
{
	// std::cout << "Float constructor called\n";
	fixedPtValue = roundf(input * (float)(1 << fracBits));
}

/* Methods From ex00 */

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called\n";
	return (fixedPtValue);
}

void Fixed::setRawBits(int const raw)
{
	fixedPtValue = raw;
}

/* Methods From ex01 */

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

/* Operator Overloading */

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
float Fixed::operator--(int i)
{
	(void)i;
	Fixed temp = *this;
	--(this->fixedPtValue);
	
	return ((float)temp.fixedPtValue / (float)(1 << fracBits));
}

/* Static Member Functions */

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
