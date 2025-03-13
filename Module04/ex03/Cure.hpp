/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:01:35 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/13 13:52:52 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		std::string	type;
	public:
		Cure();
		Cure(const Cure &other);
		Cure	&operator=(const Cure &other);
		Cure* 	clone() const;
		void	use(Character &target);
		~Cure();
};

Cure::Cure() : AMateria()
{
	type = "ice";
}

Cure*	Cure::clone() const
{
	
}

Cure::Cure(const Cure &other) : AMateria()
{
	type = "ice";
}

Cure	&Cure::operator=(const Cure &other)
{
	type = "cure";
}

void	Cure::use(Character &target)
{
	std::cout << "* heals " << target.getName()
	<< "'s wounds *" << std::endl;
}

Cure::~Cure()
{
}

#endif