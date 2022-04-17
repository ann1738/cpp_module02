/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:40:59 by anasr             #+#    #+#             */
/*   Updated: 2022/04/16 11:37:14 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	value = 0;
}

Fixed::Fixed(const Fixed& original)
{
	std::cout << "Copy constructer is called\n";
	this->value = original.value;
}

Fixed& Fixed::operator=(const Fixed& original)
{
	std::cout << "Copy assignment operator called\n";
	this->value = original.value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (value);
}

void Fixed::setRawBits( int const raw )
{
	value = raw;
}