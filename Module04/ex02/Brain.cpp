/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:58:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/11 12:59:46 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	ideas = new std::string[100];
}

Brain::Brain(const Brain &other)
{
	delete ideas;
	ideas = other.ideas;
}

Brain &Brain::operator=(const Brain &other)
{
	delete [] ideas;
	ideas = new std::string[100];
	ideas = other.ideas;
	return (*this);
}

Brain::~Brain()
{
	delete [] ideas;
}
