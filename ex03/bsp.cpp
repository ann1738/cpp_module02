/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:31:49 by anasr             #+#    #+#             */
/*   Updated: 2022/04/19 23:38:06 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed ab, ac, bc, ap, bp, cp;

	ab = ((Point)a).sideLength(a, b);
	ac = ((Point)a).sideLength(a, c);
	bc = ((Point)b).sideLength(b, c);
	ap = ((Point)a).sideLength(a, point);
	bp = ((Point)b).sideLength(b, point);
	cp = ((Point)c).sideLength(c, point);

	Fixed abc, abp, apc, pbc;

	abc =  ((Point)a).areaOfTriangle(ab, bc, ac);
	abp =  ((Point)a).areaOfTriangle(ab, bp, cp);
	apc =  ((Point)a).areaOfTriangle(ap, cp, ac);
	pbc =  ((Point)a).areaOfTriangle(bp, bc, cp);

	return (abc == (abp + apc + pbc) ? true : false);
}