/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:52:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/13 13:53:42 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter
{
	protected:
		AMateria*	materias;
		std::string	_name;
	public:
		Character();
		Character(std::string name);
		std::string const& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		~Character();
};

Character::Character()
{
}

void Character::equip(AMateria* m)
{
	
}

void Character::unequip(int idx)
{
	
}

void Character::use(int idx, ICharacter& target)
{
	
}

Character::Character(std::string name)
{
	_name = name;
}

std::string const& Character::getName() const
{
	return (_name);
}

Character::~Character()
{
}

#endif