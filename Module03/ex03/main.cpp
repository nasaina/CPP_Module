/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:39:27 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/04 13:08:44 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	bob("bob");

	bob.attack("serge");
	std::cout << bob.getName() << std::endl;
	std::cout << bob.getEnergy() << std::endl;
	bob.highFiveGuys();
}