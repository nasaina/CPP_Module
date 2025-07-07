/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:37:20 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/07 09:51:45 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void newLine()
{
	std::cout << std::endl;
}

int	main(void)
{
	try
	{
		Form taf("Name", 2, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	newLine();
	try
	{
		Bureaucrat	PDG("PDG", 2);
		Form		TAF("TAF", 1, 9);
		std::cout << PDG << std::endl;
		std::cout << TAF << std::endl;
		newLine();
		PDG.signForm(TAF);
		std::cout << TAF << std::endl;
		newLine();
		PDG.incrementation();
		PDG.signForm(TAF);
		std::cout << TAF << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
