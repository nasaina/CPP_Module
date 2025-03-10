/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:51:27 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/10 09:46:16 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	_hitpoint = 100;
	_energypoint = 50;
	_damage = 30;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
	return ;
}
