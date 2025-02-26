/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:23:01 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/26 15:36:50 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	bob("bob");
	ClapTrap	carter;

	bob.attack("carter");
	bob.attack("carter");
	bob.attack("carter");
	bob.attack("carter");
	bob.attack("carter");
	bob.attack("carter");
	bob.attack("carter");
	bob.attack("carter");
	bob.attack("carter");
	bob.attack("carter");
	bob.attack("carter");
	carter.takeDamage(5);
	carter.beRepaired(10);
	bob.beRepaired(4);
	std::cout << bob.getEnergyPoint() << std::endl;
	std::cout << carter.getHitPoint() << std::endl;
}