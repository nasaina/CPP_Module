/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:00:19 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/10 13:32:12 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "Birth of a WrongCat" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const std::string input) : WrongAnimal(input)
{
	std::cout << "Birth of a WrongCat" << std::endl;
	type = input;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal()
{
	this->type = other.type;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	type = other.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Ouaim ouaim" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat just died" << std::endl;
}
