/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:29:59 by anasr             #+#    #+#             */
/*   Updated: 2022/05/22 19:45:31 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	/* SUBJECT FILE TEST */
	{
		std::cout << "\e[95m*** SUBJECT FILE TEST ***\e[0m\n";
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
	
		std::cout << b << std::endl;
	
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	/* COMPARISON OPERATORS */
	{
		std::cout << "\n\e[95m*** COMPARISON OPERATORS TEST ***\e[0m\n";
		//  ">" and "<"
		Fixed big(100.333f);
		Fixed small(100.331f);
		if (big > small)
			std::cout << big << " is bigger than " << small << std:: endl;
		else
			std::cout << big << " is smaller than " << small << std:: endl;
		big = Fixed(100.0f);
		small = Fixed(98.0f);
		if (small < big)
			std::cout << small << " is smaller than " << big << std:: endl;
		else
			std::cout << small << " is smaller than " << big << std:: endl;
		//  ">=" and "<="
		big = Fixed(100.1f);
		small = Fixed(100.1f);
		if (big >= small)
			std::cout << big << " is bigger/equal than " << small << std:: endl;
		else
			std::cout << big << " is smaller than " << small << std:: endl;
		if (big <= small)
			std::cout << big << " is smaller/equal than " << small << std:: endl;
		else
			std::cout << big << " is bigger than " << small << std:: endl;
		//  "==" and "!="
		if (big == small)
			std::cout << big << " is equal to " << small << std:: endl;
		else if (big != small)
			std::cout << big << " is not equal to " << small << std:: endl;
		big = Fixed(101.0f);
		small = Fixed(100.0f);
		if (big == small)
			std::cout << big << " is equal to " << small << std:: endl;
		else if (big != small)
			std::cout << big << " is not equal to " << small << std:: endl;
	}
	/* ARITHMETICS OPERATORS */
	{
		std::cout << "\n\e[95m*** ARITHMETICS OPERATORS TEST ***\e[0m\n";
		// "+" and "-"
		Fixed add1(5.67f), add2(10.1f);
		Fixed result(add1 + add2);
		std::cout << add1 << " + " << add2 << " = " << result << std::endl;
		
		Fixed sub1(7.52f), sub2(5.52f);
		result = Fixed(sub1 - sub2);
		std::cout << sub1 << " - " << sub2 << " = " << result << std::endl;
		
		// "*" and "/"
		Fixed mul1(7.52f), mul2(2);
		result = Fixed(mul1 * mul2);
		std::cout << mul1 << " * " << mul2 << " = " << result << std::endl;
		
		Fixed div1(15.0391f), div2(7.52f);
		result = Fixed(div1 / div2);
		std::cout << div1 << " / " << div2 << " = " << result << std::endl;
	}
	/* INCREMENT/DECREMENT */
	{
		std::cout << "\n\e[95m*** INCREMENT/DECREMENT TEST ***\e[0m\n";
		Fixed i, d;
		std::cout << "Initial value of i is " << i << std::endl;
		std::cout << "\e[92m[POST INCREMENT]\e[0m\n";
		std::cout << "i++ is " << i++ << std::endl; 
		std::cout << "and now it's " << i << std::endl;
		std::cout << "\e[92m[PRE INCREMENT]\e[0m\n";
		std::cout << "i is " << i << std::endl;
		std::cout << "++i is " << ++i << std::endl;
		std::cout << "\nInitial value of d is " << d << std::endl;
		std::cout << "\e[92m[POST DECREMENT]\e[0m\n";
		std::cout << "d-- is " << d-- << std::endl; 
		std::cout << "and now it's " << d << std::endl;
		std::cout << "\e[92m[PRE DECREMENT]\e[0m\n";
		std::cout << "d is " << d << std::endl;
		std::cout << "--d is " << --d << std::endl;
	}
	/* MIN()/MAX() */
	{
		std::cout << "\n\e[95m*** MIN()/MAX() TEST ***\e[0m\n";
		Fixed Min(92.51f), Max(188.12f);
		std::cout << "The minimum between " << Min << " and " << Max << " is " << Min.min(Min, Max) << std::endl;
		std::cout << "The maximum between " << Min << " and " << Max << " is " << Min.max(Min, Max) << std::endl << std::endl;
	}
	return 0;
}