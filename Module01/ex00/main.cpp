/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 08:30:23 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/05 09:29:53 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie *zombie;

	zombie = newZombie("Hercule");
	zombie->announce();
	randomChump("lavaka");
	delete[] zombie;
}
