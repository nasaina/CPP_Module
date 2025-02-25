/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:17:08 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/25 18:09:16 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

std::ostream	&operator<<(std::ostream &os, const Fixed &other);

Fixed	onePoint(Point const a, Point const b, Point const c)
{
	Fixed	tmp1;
	Fixed	sign(-1);
	Fixed	tmp2;
	Fixed	tmp3;
	Fixed	div(1 / 2);
	Fixed	result;

	tmp1 = a.getCoordx() * (b.getCoordy() - c.getCoordy());
	tmp2 = b.getCoordx() * (c.getCoordy() - a.getCoordy());
	tmp3 = c.getCoordx() * (a.getCoordy() - b.getCoordy());
	result = div * (tmp1 + tmp2 + tmp3);
	if (result.getValue() < 0)
		result = result * sign;
	return (result);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed abc = onePoint(a, b, c);
	Fixed pab = onePoint(point, a, b);
	Fixed pbc = onePoint(point, b, c);
	Fixed pca = onePoint(point, c, a);
	std::cout << "abc =" << abc;
	std::cout << "pab =" << pab;
	std::cout << "pbc =" << pbc;
	std::cout << "pca =" << pca;
	if (abc == (pab + pbc + pca))
		return (true);
	return (false);
}