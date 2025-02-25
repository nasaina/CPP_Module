/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:36:17 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/25 17:37:16 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
	return ;
}

Point::Point(const Point &other)
{
	*this = other;
	return ;
}

Point::Point(const float otherx, const float othery)
{
	Fixed tmpx(otherx);
	Fixed tmpy(othery);

	(Fixed)this->x = tmpx;
	(Fixed)this->y = tmpy;
}

Point &Point::operator=(const Point &other)
{
	(Fixed)this->x = other.x;
	(Fixed)this->y = other.y;
	return (*this);
}

bool Point::operator==(const Point &other) const
{
	if (this->x == other.x && this->y == other.y)
		return (true);
	return (false);
}

Fixed	Point::getCoordx(void) const
{
	return (x);
}

Fixed	Point::getCoordy(void) const
{
	return (y);
}

Point::~Point()
{
	return ;
}
