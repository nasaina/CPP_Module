/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:40:45 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/05 12:50:07 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string& 	stringREF = string;

	std::cout << "/******************* adresses ****************/" << std::endl;
	std::cout << &string << std::endl;
	std::cout << &stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << "/******************** value *****************/" << std::endl;
	std::cout << string << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	return (0);
}
