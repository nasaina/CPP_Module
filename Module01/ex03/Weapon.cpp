/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:23:18 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/20 09:22:07 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(void)
{
	return ;
}

Weapon::Weapon(std::string input)
{
	type = input;
}

Weapon::~Weapon()
{
	return ;
}

void	Weapon::setType(std::string input)
{
	type = input;
}

const std::string&	Weapon::getType(void)
{
	const std::string&	out = type;

	return (out);
}
