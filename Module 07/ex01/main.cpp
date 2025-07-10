/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:17:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/10 13:10:17 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	up(const int &c)
{
	std::cout << c << '\n';
}

void	up(int c)
{
	c++;
}

int main( void )
{
	int	T[3] = {1, 2, 3};

	::iter(T, 3, up);
	for (int i = 0; i < 3; i++)
	{
		std::cout << T[i];
	}
	
	return 0;
}
