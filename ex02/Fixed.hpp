/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:36:22 by anasr             #+#    #+#             */
/*   Updated: 2022/04/19 13:37:32 by anasr            ###   ########.fr       */
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

	//comparison operators
	bool operator>(const Fixed& other_f);
	bool operator>=(const Fixed& other_f);
	bool operator<(const Fixed& other_f);
	bool operator<=(const Fixed& other_f);
	bool operator==(const Fixed& other_f);
	bool operator!=(const Fixed& other_f);

	//arithmetic operators
	Fixed operator+(const Fixed& other_f);
	Fixed operator-(const Fixed& other_f);
	Fixed operator*(const Fixed& other_f);
	Fixed operator/(const Fixed& other_f);
	
	//increment/decrement
	Fixed& operator++(void);
	Fixed operator++(int);
	Fixed& operator--(void);
	float operator--(int i);

	//static member functions
	static Fixed& min(Fixed &f1, Fixed &f2);
	static Fixed& min(const Fixed &f1, const Fixed &f2);
	static Fixed& max(Fixed &f1, Fixed &f2);
	static Fixed& max(const Fixed &f1, const Fixed &f2);

};

std::ostream& operator<<(std::ostream& console_out, const Fixed& current_fixed);

#endif