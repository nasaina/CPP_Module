/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:54:38 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/10 13:29:52 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal()
{
	std::cout << "Birth of one Animal" << std::endl;
	type = "Animal";
}

Animal::Animal(const std::string input)
{
	std::cout << "Birth of one Animal" << std::endl;
	type = input;
}

Animal::Animal(const Animal &other)
{
	this->type = other.type;
}

Animal	&Animal::operator=(const Animal &other)
{
	type = other.type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal ROARS LOUDER" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal just died" << std::endl;
}
