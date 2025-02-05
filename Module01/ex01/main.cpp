/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:30:59 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/05 12:38:44 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	int		N;
	Zombie	*zombies;

	N = 6;
	zombies = zombieHorde(N, "Poutine");
	for (int i = 0; i < N; i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;
}
