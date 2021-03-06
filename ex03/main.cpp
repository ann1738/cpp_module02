/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:29:59 by anasr             #+#    #+#             */
/*   Updated: 2022/05/23 11:13:39 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	/* constructing the vertices and the point to be tested */
	Point a(0.0f, 0.0f);
	Point b(0.0f, 3.0f);
	Point c(3.0f, 0.0f);
	Point p(0.0f, 0.0f);

	/* calling the function that will test if the point is inside the triangle */
	if (bsp(a, b, c, p))
		std::cout << "The point is inside the given triangle! ;)\n";
	else
		std::cout << "The point is outside the given triangle! ;<(\n";
	return (0);

	/* testing copy constructor */
	// Point p(b);

	/* testing copy constructor */
	// Point p;
	// p = c;
}
