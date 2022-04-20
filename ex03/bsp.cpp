/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasr <anasr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:31:49 by anasr             #+#    #+#             */
/*   Updated: 2022/04/20 15:28:32 by anasr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed ab, ac, bc, ap, bp, cp;

	if (((Point)point).checkSameAsVertix(point, a) || ((Point)point).checkSameAsVertix(point, b) \
		|| ((Point)point).checkSameAsVertix(point, c))
		return (false);
	if (((Point)point).pointOnLine(point, a, b) /*|| ((Point)point).pointOnLine(point, a, c) \
		|| ((Point)point).pointOnLine(point, b, c)*/)
		return (false);
	ab = ((Point)a).sideLength(a, b);
	ac = ((Point)a).sideLength(a, c);
	bc = ((Point)b).sideLength(b, c);
	ap = ((Point)a).sideLength(a, point);
	bp = ((Point)b).sideLength(b, point);
	cp = ((Point)c).sideLength(c, point);

	Fixed abc, abp, apc, pbc;

	abc =  ((Point)a).areaOfTriangle(ab, bc, ac);
	std::cout << "abc area is " << abc << std::endl;
	abp =  ((Point)a).areaOfTriangle(ab, bp, ap);
	std::cout << "abp area is " << abp << std::endl;
	apc =  ((Point)a).areaOfTriangle(ap, cp, ac);
	std::cout << "apc area is " << apc << std::endl;
	pbc =  ((Point)a).areaOfTriangle(bp, bc, cp);
	std::cout << "pbc area is " << pbc << std::endl;
	std::cout << abp + apc + pbc << std::endl;
	return ((abp + apc + pbc) >= (abc - 0.05f) && (abp + apc + pbc) <= (abc + 0.05f) ? true : false);
}