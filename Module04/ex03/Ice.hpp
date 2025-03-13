/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:01:35 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/13 13:30:02 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria, public Character
{
	private:
		std::string	type;
	public:
		Ice();
		Ice(const Ice &other);
		Ice		&operator=(const Ice &other);
		Ice* 	clone() const;
		void	use(Character &target);
		~Ice();
};

Ice::Ice() : AMateria()
{
	type = "ice";
}

Ice::Ice(const Ice &other)
{
	type = "ice";
}

Ice	&Ice::operator=(const Ice &other)
{
	type = "ice";
}

void	Ice::use(Character &target)
{
	std::cout << "* shoots an ice bolt at "
	<< target.getName() << " *" << std::endl;
}

Ice::~Ice()
{
}

#endif