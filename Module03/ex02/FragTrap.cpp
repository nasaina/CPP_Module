/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:05:06 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/04 08:22:12 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap constructor called" << std::endl;
	setDamage(30);
	setEnergy(100);
	setHit(100);
	return ;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	setDamage(30);
	setEnergy(100);
	setHit(100);
	setName(name);
	return ;
}

FragTrap::FragTrap(const FragTrap &other)
{
	*this = other;
}
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	this->setDamage(other.getdamage());
	this->setEnergy(other.getEnergyPoint());
	this->setHit(other.getHitPoint());
	this->setName(other.getName());
	return (*this);
}

void 	FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << getName()
		<< " wants to give five energy point to you." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
	return ;
}
