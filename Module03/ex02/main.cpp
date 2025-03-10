/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:39:27 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/04 12:35:39 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	bob("bob");

	bob.attack("serge");
	std::cout << bob.getName() << std::endl;
	std::cout << bob.getDamage() << std::endl;
	bob.highFiveGuys();
}