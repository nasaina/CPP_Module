/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:37:20 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/07 10:18:54 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void	newLine(void)
{
	std::cout << std::endl;
}

int	main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	try
	{
		Bureaucrat	PDG("PDG", 2);
		PresidentialPardonForm	President("Madagascar");
		ShrubberyCreationForm	Tt("home");
		RobotomyRequestForm		Robot("death");

		PDG.signForm(Tt);
		PDG.signForm(Robot);
		newLine();
		PDG.executeForm(Tt);
		newLine();
		PDG.signForm(President);
		PDG.executeForm(President);
		newLine();
		for (size_t i = 0; i < 9; i++)
			PDG.executeForm(Robot);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
