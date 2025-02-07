/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:19:01 by nandrian          #+#    #+#             */
/*   Updated: 2025/01/27 15:19:03 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char CharUpper(char c)
{
	return (toupper(c));
}

void	StrUpper(std::string input)
{
	char c;

	for (size_t i = 0; input[i]; i++)
	{
		c = input[i];
		input[i] = CharUpper(c);
	}
	std::cout << input;
}

int	main(int ac, char **av)
{
	std::string	input;

	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			input = av[i];
			StrUpper(input);
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
		<< std::endl;
	return (0);
}
