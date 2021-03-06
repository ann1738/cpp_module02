/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:36:22 by anasr             #+#    #+#             */
/*   Updated: 2022/05/22 19:25:33 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					fixedPtValue;
	static const int	fracBits = 8;
public:
	Fixed();
	Fixed(const Fixed& original);
	Fixed& operator=(const Fixed& original);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif