/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:23:18 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/06 16:24:53 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string input)
{
	type = input;
}

Weapon::~Weapon()
{
}

void	Weapon::setType(std::string input)
{
	type = input;
}

std::string&	Weapon::getType(void)
{
	std::string&	out = type;

	return (out);
}
