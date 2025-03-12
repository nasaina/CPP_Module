/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:40:45 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/11 15:26:56 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string& 	stringREF = string;

	std::cout << "/******************* adresses ****************/" << std::endl;
	std::cout << "string    : " << &string << std::endl;
	std::cout << "pointer   : " << stringPTR << std::endl;
	std::cout << "reference : " << &stringREF << std::endl;

	std::cout << "/******************** value *****************/" << std::endl;
	std::cout << "string    : " << string << std::endl;
	std::cout << "pointer   : " << *stringPTR << std::endl;
	std::cout << "reference : " << stringREF << std::endl;
	return (0);
}
