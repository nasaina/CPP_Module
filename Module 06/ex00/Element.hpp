/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Element.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:55:09 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/01 13:02:33 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ELEMENT_HPP
# define ELEMENT_HPP

# include <iostream>
# include "head.h"

class Element
{
	private:
		char		_c;
		int			_i;
		float		_f;
		double		_d;
		type		_type;
	public:
		Element();
		Element(std::string litteral);
		Element(const Element &other);
		Element	&operator=(const Element &other);
		void	printElement(void);

		char	getChar(void) const;
		int		getInt(void) const;
		float	getFloat(void) const;
		double	getDouble(void) const;
		type	getType(void) const;


		~Element();
};

#endif