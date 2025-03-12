/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:01:35 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/12 13:31:16 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>

class Cure
{
	private:
		std::string	type;
	public:
		Cure();
		Cure(const Cure &other);
		Cure	&operator=(const Cure &other);
		~Cure();
};

Cure::Cure()
{
	type = "ice";
}

Cure::Cure(const Cure &other)
{
	type = "ice";
}

Cure	&Cure::operator=(const Cure &other)
{
	type = "cure";
}

Cure::~Cure()
{
}

#endif