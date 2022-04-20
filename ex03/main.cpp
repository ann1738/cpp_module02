/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:29:59 by anasr             #+#    #+#             */
/*   Updated: 2022/04/20 12:51:36 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point a(0.0f, 0.0f);
	Point b(0.0f, 10.0f);
	Point c(10.0f, 0.0f);
	Point p(1.0f, 1.0f);

	if (bsp(a, b, c, p))
		std::cout << "The point is inside the given triangle! ;)\n";
	else
		std::cout << "The point is not inside the given triangle! ;)\n";
}