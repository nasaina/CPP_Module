/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:24:22 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/03 09:36:16 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main()
{
	std::string	input;
	PhoneBook	PhoneBook;

	while (1)
	{
		std::cout << "ADD | SEARCH | EXIT : ";
		if (!std::getline(std::cin, input))
		{
			input.clear();
			_exit(1);
		}
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
			PhoneBook.AddContact();
		else if (input == "SEARCH")
			PhoneBook.PrintContacts();
		else if (input == "")
			continue ;
	}
	return (0);
}
