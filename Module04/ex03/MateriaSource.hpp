/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:32:04 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/13 13:13:19 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		
	public:
		MateriaSource();
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
		~MateriaSource();
};

MateriaSource::MateriaSource() : IMateriaSource()
{
	
}

void MateriaSource::learnMateria(AMateria*)
{

}

AMateria* MateriaSource::createMateria(std::string const & type)
{

}


MateriaSource::~MateriaSource()
{
}

#endif