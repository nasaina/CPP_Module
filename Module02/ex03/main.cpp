/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:00:39 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/26 08:35:17 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool			bsp( Point const a, Point const b, Point const c, Point const point );
std::ostream	&operator<<(std::ostream &os, const Fixed &other);

void			printTriangle( Point const a, Point const b, Point const c)
{
	std::cout << "/* **** triangle **** */" << std::endl;
	std::cout << "Point a";
	a.print();
	std::cout << std::endl << "Point b";
	b.print();
	std::cout << std::endl << "Point c";
	c.print();
}

void			checkBSP( Point const a, Point const b, Point const c, Point const point )
{
	std::cout << std::endl << "/* ****** point ****** */" << std::endl;
	std::cout << "Point point";
	point.print();
	if (bsp(a, b, c, point))
		std::cout << " is inside of the triangle"  << std::endl;
	else
		std::cout << " is outside of the triangle" << std::endl;
}

int	main(void)
{
	Point a(0, 0);
	Point b(5, 0);
	Point c(2, 4);

	Point point(2, 2);
	Point point2(6, 5);
	Point point3(-1, 1);

	printTriangle(a, b, c);
	checkBSP(a, b, c, point);
	checkBSP(a, b, c, point2);
	checkBSP(a, b, c, point3);
	return (0);
}
