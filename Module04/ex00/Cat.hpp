/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:55:16 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/10 13:31:31 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	private:
		
	public:
		Cat();
		Cat(const std::string input);
		Cat(const Cat &other);
		Cat	&operator=(const Cat &other);
		void	makeSound(void) const;
		~Cat();
};

#endif