/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:39:27 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/26 17:51:41 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.cpp"

int	main(void)
{
	ScavTrap	bob("bob");

	bob.attack("serge");
	std::cout << bob.getName() << std::endl;
	std::cout << bob.getEnergyPoint() << std::endl;
}