/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:17:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/04 16:34:41 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data *ptr = new Data;

	ptr->content = "Big data";
	std::cout << ptr << std::endl;
	uintptr_t raw = Serializer::serialize(ptr);
	ptr = Serializer::deserialize(raw);
	
	std::cout << ptr << std::endl;
	std::cout << ptr->content;
	delete ptr;
	return (0);
}