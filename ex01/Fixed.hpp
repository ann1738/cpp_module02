/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:36:22 by anasr             #+#    #+#             */
/*   Updated: 2022/04/16 14:18:48 by ann              ###   ########.fr       */
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
	Fixed(const int input);
	Fixed(const float input);
	Fixed(const Fixed& original);
	Fixed& operator=(const Fixed& original);
	std::ostream& operator<<(std::ostream& console_out);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	int toInt( void ) const;
};

#endif