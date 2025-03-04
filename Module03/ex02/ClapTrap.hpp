/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:24:17 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/04 07:45:39 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
private:
	std::string	_name;
	int			_hitpoint;
	int			_energypoint;
	int			_damage;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap	&operator=(const ClapTrap &other);

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

	void		setHit(const int hit);
	void		setEnergy(const int energy);
	void		setDamage(const int damage);
	void		setName(const std::string name);

	int			getHitPoint(void) const;
	int			getEnergyPoint(void) const;
	int			getdamage(void) const;
	std::string	getName(void) const;
	~ClapTrap(void);
};

#endif