/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:29:59 by anasr             #+#    #+#             */
/*   Updated: 2022/04/18 13:32:25 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Fixed b;
	Fixed c(3.7231f);
	Fixed d(3.7230f);

	std::cout << "\e[34mb is " << b++ << std::endl;
	std::cout << "aa is " << ++b << "\e[0m" << std::endl;
	if (c > d)
		std::cout << "c is greater than d\n";
	else
		std::cout << "c is lesser than d\n";

	return 0;
}