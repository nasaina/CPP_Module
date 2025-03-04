/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:05:06 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/04 08:08:43 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap constructor called" << std::endl;
	setDamage(20);
	setEnergy(50);
	setHit(100);
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	setDamage(20);
	setEnergy(50);
	setHit(100);
	setName(name);
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	*this = other;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	this->setDamage(other.getdamage());
	this->setEnergy(other.getEnergyPoint());
	this->setHit(other.getHitPoint());
	this->setName(other.getName());
	return (*this);
}

void 	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName()
		<< " is now in Gatekeeper mode." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}
