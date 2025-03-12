/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:01:35 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/12 13:06:37 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>

class Ice
{
	private:
		std::string	type;
	public:
		Ice();
		Ice(const Ice &other);
		Ice	&operator=(const Ice &other);
		~Ice();
};

Ice::Ice()
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

Ice::~Ice()
{
}

#endif