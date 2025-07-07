/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:37:20 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/07 09:50:10 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void newLine()
{
	std::cout << std::endl;
}

int	main(void)
{
	try
	{
		Bureaucrat PDG("PDG", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	newLine();
	try
	{
		Bureaucrat boss("PDG", 1);

		std::cout << boss << std::endl;
		boss.decrementation();
		std::cout << boss << std::endl;
		boss.incrementation();
		std::cout << boss << std::endl;
		boss.incrementation();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	newLine();
	try
	{
		Bureaucrat noBoss("noBoss", 150);
		std::cout << noBoss << std::endl;
		noBoss.decrementation();
		std::cout << noBoss << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	newLine();
	try
	{
		Bureaucrat	Excluded("Excluded", 151);
		std::cout << Excluded << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

