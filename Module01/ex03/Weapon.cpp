/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:23:18 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/05 13:27:21 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(void)
{
	
}

Weapon::~Weapon(void)
{
	return ;
}

void	Weapon::setType(std::string input)
{
	type = input;
}

const std::string& 	Weapon::getType(void)
{
	const std::string&	types = type;

	return (types);
}

