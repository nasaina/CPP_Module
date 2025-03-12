/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:55:20 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/20 09:46:21 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string input)
{
	weaponB = NULL;
	name = input;
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void	HumanB::setWeapon(Weapon &weapons)
{
	weaponB = &weapons;
	return ;
}

void	HumanB::attack(void)
{
	if (weaponB != NULL)
		std::cout << name << " attacks with their " << weaponB->getType() << std::endl;
	return ;
}
