/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:39:27 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/04 08:31:00 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	bob("bob");

	std::cout << bob.getName() << std::endl;
	std::cout << bob.getEnergyPoint() << std::endl;
	bob.guardGate();
}
