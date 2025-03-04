/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:37:04 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/04 12:38:37 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor called" << std::endl;
	_hitpoint = 10;
	_energypoint = 10;
	_damage = 0;
	return ;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor called" << std::endl;
	_name = name;
	_hitpoint = 10;
	_energypoint = 10;
	_damage = 0;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	this->_name = other._name;
	this->_hitpoint = other._hitpoint;
	this->_energypoint = other._energypoint;
	this->_damage = other._damage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitpoint > 0 && _energypoint > 0)
	{
		std::cout << "ClapTrap " << _name <<  " attacks " << target
		<< ", causing " << _damage << " points of damage!" << std::endl;
		_energypoint -= 1;
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitpoint == 0)
	{
		std::cout << _name << " does not have any hit points" << std::endl;
		return ;
	}
	_hitpoint -= amount;
	if (_hitpoint < 0)
		_hitpoint = 0;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energypoint == 0)
	{
		std::cout << _name << " does not have any energy points" << std::endl;
		return ;
	}
	_energypoint -= 1;
	_hitpoint += amount;
	return ;
}

int			ClapTrap::getHit(void) const
{
	return (_hitpoint);
}

int			ClapTrap::getEnergy(void) const
{
	return (_energypoint);
}

int			ClapTrap::getDamage(void) const
{
	return (_damage);
}

std::string	ClapTrap::getName(void) const
{
	return (_name);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}
