/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:00:19 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/11 13:54:48 by nandrian         ###   ########.fr       */
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
	type = other.type;
	delete brain;
	brain = new Brain();
	brain = other.brain;
}

Cat	&Cat::operator=(const Cat &other)
{
	type = other.type;
	delete brain;
	brain = new Brain();
	brain = other.brain;
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
