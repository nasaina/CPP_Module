/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:30:59 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/12 06:43:27 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

Zombie	*zombieHorde(int N, std::string name);

int	main(int ac, char **av)
{
	int		N;
	Zombie	*zombies;

	if (ac == 3)
	{
		N = atoi(av[1]);
		zombies = zombieHorde(N, av[2]);
		if (!zombies)
		{
			std::cout << "N should be positive" << std::endl;
			return (1);
		}
		for (int i = 0; i < N; i++)
		{
			zombies[i].announce();
		}
		delete[] zombies;
	}
	else
		std::cout << "arguments required : Number of zombies | name of Horde"
		<< std::endl;
	return (0);
}
