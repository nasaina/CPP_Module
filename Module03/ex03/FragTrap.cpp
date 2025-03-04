/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:05:06 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/04 12:32:18 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap constructor called" << std::endl;
	_damage = 30;
	_energypoint = 100;
	_hitpoint = 100;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	_damage = 30;
	_energypoint = 100;
	_hitpoint = 100;
	_name = name;
	return ;
}

FragTrap::FragTrap(const FragTrap &other)
{
	*this = other;
}
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	_name = other._name;
	_damage = other._damage;
	_hitpoint = other._hitpoint;
	_energypoint = other._energypoint;
	return (*this);
}

void 	FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << _name
		<< " wants to give five energy point to you." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
	return ;
}
