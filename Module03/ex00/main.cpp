/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:23:01 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/26 16:28:41 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	bob("bob");
	ClapTrap	carter;

	bob.attack("carter");
	bob.takeDamage(10);
	std::cout << bob.getHitPoint() << std::endl;
	bob.beRepaired(10);
	std::cout << bob.getEnergyPoint() << std::endl;
	bob.attack("carter");
	bob.beRepaired(10);
	std::cout << bob.getEnergyPoint() << std::endl;
	bob.attack("carter");
	bob.beRepaired(10);
	std::cout << bob.getEnergyPoint() << std::endl;
	bob.attack("carter");
	bob.beRepaired(10);
	std::cout << bob.getEnergyPoint() << std::endl;
	bob.attack("carter");
	bob.beRepaired(10);
	std::cout << bob.getEnergyPoint() << std::endl;
	bob.attack("carter");
	bob.beRepaired(10);
	std::cout << bob.getEnergyPoint() << std::endl;
}