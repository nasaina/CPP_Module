/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:00:19 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/11 12:56:26 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Birth of a Cat" << std::endl;
	brain = new Brain();
	type = "Cat";
}

Cat::Cat(const std::string input) : Animal(input)
{
	std::cout << "Birth of a Cat" << std::endl;
	brain = new Brain();
	type = input;
}

Cat::Cat(const Cat &other) : Animal()
{
	this->type = other.type;
}

Cat	&Cat::operator=(const Cat &other)
{
	type = other.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaou miaou" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat just died" << std::endl;
}
