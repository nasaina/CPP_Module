/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:48:21 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/11 13:35:45 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const std::string input);
		Animal(const Animal &other);
		Animal	&operator=(const Animal &other);
		virtual void	makeSound(void) const = 0;
		std::string	getType(void) const;
		virtual ~Animal();
};

#endif