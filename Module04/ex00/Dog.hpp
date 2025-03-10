/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:55:16 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/10 13:31:06 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	private:
		
	public:
		Dog();
		Dog(const std::string input);
		Dog(const Dog &other);
		Dog	&operator=(const Dog &other);
		void	makeSound(void) const;
		~Dog();
};

#endif