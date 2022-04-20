/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:29:59 by anasr             #+#    #+#             */
/*   Updated: 2022/04/20 15:36:36 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point a(0.0f, 0.0f);
	Point b(0.0f, 10.0f);
	Point c(10.0f, 0.0f);
	Point p(5.0f, 0.0f);
	// figure out a way to exclude the points on the edge of the triangle

	if (bsp(a, b, c, p))
		std::cout << "The point is inside the given triangle! ;)\n";
	else
		std::cout << "The point is not inside the given triangle! ;)\n";
}
