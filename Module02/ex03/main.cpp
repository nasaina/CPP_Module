/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:00:39 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/25 18:04:39 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point a(0, 0);
	Point b(5, 0);
	Point c(2, 4);

	Point point(2, 2);
	Point point2(6, 5);

	if (bsp(a, b, c, point))
		std::cout << "in\n";
	else
		std::cout << "out\n";
	return (0);
}
