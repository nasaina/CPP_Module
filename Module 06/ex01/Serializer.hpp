/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:52:18 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/04 16:41:28 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP 
# define SERIALIZER_HPP 

# include "Data.h"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer	&operator=(const Serializer &other);
		
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
		~Serializer();
};

#endif