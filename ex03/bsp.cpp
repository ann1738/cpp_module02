/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ann <ann@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:31:49 by anasr             #+#    #+#             */
/*   Updated: 2022/05/23 11:11:49 by ann              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* function to find the 2d cross product */
Fixed	crossProduct(const Point& A, const Point& B)
{
	Fixed temp;

	temp = A.getX() * B.getY() - A.getY() * B.getX();
	return (temp);
}

/* function to determine the vector given two points */
Point	getVector(const Point& A, const Point& B)
{
	Fixed abX(A.getX() - B.getX());
	Fixed abY(A.getY() - B.getY());
	Point temp(abX.toFloat(), abY.toFloat());

	return (temp);
}

/* *********************************************************************** */
/* *********************************************************************** */
/* **********   B *                                             ********** */
/* **********     #  #                                          ********** */
/* **********     #    #                                        ********** */
/* **********     #      #          is p inside the triangle ?  ********** */
/* **********     #   *p   #                                    ********** */
/* **********     #          #                                  ********** */
/* **********   A * # # # # # * C                               ********** */
/* *********************************************************************** */
/* *********************************************************************** */

/* the main required function that will test if the point is in the triangle */
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point AB(getVector(a, b)), BC(getVector(b, c)), CA(getVector(c, a)), AP(getVector(a, point)), BP(getVector(b, point)), CP(getVector(c, point));
	Fixed APxAB(crossProduct(AP, AB)), BPxBC(crossProduct(BP, BC)), CPxCA(crossProduct(CP, CA));

	return (((APxAB > 0 && BPxBC > 0 && CPxCA > 0) || (APxAB < 0 && BPxBC < 0 && CPxCA < 0)) ?  true : false);
}
