/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:40:59 by anasr             #+#    #+#             */
/*   Updated: 2022/04/17 11:01:45 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	fixedPtValue = 0;
}

Fixed::Fixed(const int input)
{
	//check negative?
	fixedPtValue = input;
	fixedPtValue <<= 8;
}

Fixed::Fixed(const float input)
{
	
}

Fixed::Fixed(const Fixed& original)
{
	std::cout << "Copy constructer is called\n";
	this->fixedPtValue = original.fixedPtValue;
}

Fixed& Fixed::operator=(const Fixed& original)
{
	std::cout << "Copy assignment operator called\n";
	this->fixedPtValue = original.fixedPtValue;
	return (*this);
}

std::ostream& Fixed::operator<<(std::ostream& console_out)
{
	console_out << this->fixedPtValue;
	return (console_out);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (fixedPtValue);
}

void Fixed::setRawBits( int const raw )
{
	fixedPtValue = raw;
}

int Fixed::toInt( void ) const
{
	return (fixedPtValue >> 8);
}
//seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm

int Fixed::toInt( void ) const
{
	return (fixedPtValue >> 8);
}

float toFloat( void ) const
{
	~
}