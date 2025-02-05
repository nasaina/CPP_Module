/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:29:36 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/05 12:37:12 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{
	return ;
}

Zombie::~Zombie()
{
	std::cout << this->name << ": destroyed" << std::endl;
	return ;
}

void	Zombie::setName(std::string input)
{
	name = input;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}