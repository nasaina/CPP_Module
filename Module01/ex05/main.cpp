/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:34:40 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/12 08:14:49 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	harley;

	if (ac != 2)
	{
		std::cout << "Use ./harlFilter <your complain message>" << std::endl;
		return (1);
	}
	harley.complain(av[1]);
	return (0);
}
