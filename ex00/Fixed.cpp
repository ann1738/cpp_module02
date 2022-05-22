/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:40:59 by anasr             #+#    #+#             */
/*   Updated: 2022/05/22 19:25:49 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Orthodox Canonical Form Requirements */

// default constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	fixedPtValue = 0;
}

// copy constructor
Fixed::Fixed(const Fixed& original)
{
	std::cout << "Copy constructer is called\n";
	this->fixedPtValue = original.fixedPtValue;
}

// copy assignment operator overload
Fixed& Fixed::operator=(const Fixed& original)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &original)
		this->fixedPtValue = original.fixedPtValue;
	return (*this);
}

// destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

/* Other Member Functions */

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (fixedPtValue);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called\n";
	fixedPtValue = raw;
}
