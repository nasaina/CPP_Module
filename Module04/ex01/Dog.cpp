/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:00:19 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/11 13:50:02 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Birth of a Dog" << std::endl;
	brain = new Brain();
	type = "Dog";
}

Dog::Dog(const std::string input) : Animal(input)
{
	std::cout << "Birth of a Dog" << std::endl;
	brain = new Brain();
	type = input;
}

Dog::Dog(const Dog &other) : Animal()
{
	type = other.type;
	delete brain;
	brain = new Brain();
	brain = other.brain;
}

Dog	&Dog::operator=(const Dog &other)
{
	type = other.type;
	delete brain;
	brain = new Brain();
	brain = other.brain;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Ouaf Ouaf" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog just died" << std::endl;
	delete brain;
}
