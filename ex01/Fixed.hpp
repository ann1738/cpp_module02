/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:36:22 by anasr             #+#    #+#             */
/*   Updated: 2022/04/18 10:14:28 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

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
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;

};

std::ostream& operator<<(std::ostream& console_out, const Fixed& current_fixed);

#endif