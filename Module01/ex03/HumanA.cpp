/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:55:20 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/06 16:40:25 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string input, Weapon& weapons)
{
	weaponA = &weapons;
	name = input;
	return ;
}

HumanA::~HumanA()
{
	return ;
}

void	HumanA::setWeapon(Weapon &weapons)
{
	weaponA = &weapons;
	return ;
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weaponA->getType() << std::endl;
}