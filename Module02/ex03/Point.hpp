/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:50:53 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/25 17:36:39 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	const Fixed	x;
	const Fixed	y;
public:
	Point();
	Point(const Point &other);
	Point(const float otherx, const float othery);
	Point	&operator=(const Point &other);
	bool	operator==(const Point &other) const;

	Fixed	getCoordx(void) const;
	Fixed	getCoordy(void) const;
	~Point();
};

#endif