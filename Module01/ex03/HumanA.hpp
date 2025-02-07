/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:28:15 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/06 16:42:49 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon	*weaponA;
	public:
		HumanA(std::string input, Weapon& weapons);
		~HumanA();
		void	attack(void);
		void	setWeapon(Weapon &weapons);
};

#endif