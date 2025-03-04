/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:05:06 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/04 13:14:22 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap constructor called" << std::endl;
	_damage = 20;
	_energypoint = 50;
	_hitpoint = 100;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	_damage = 20;
	_energypoint = 50;
	_hitpoint = 100;
	_name = name;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	*this = other;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	_name = other._name;
	_energypoint = other._energypoint;
	_hitpoint = other._hitpoint;
	_damage = other._damage;
	return (*this);
}

void 	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name
		<< " is now in Gatekeeper mode." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}
