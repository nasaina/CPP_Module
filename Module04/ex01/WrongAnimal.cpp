/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:54:38 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/10 13:36:59 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal()
{
	std::cout << "Birth of one Animal but Wrong" << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const std::string input)
{
	std::cout << "Birth of one Animal but Wrong" << std::endl;
	type = input;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->type = other.type;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	type = other.type;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal ROARS LOUDER" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal just died" << std::endl;
}
