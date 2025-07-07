/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:37:20 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/07 10:25:21 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	AForm* rrf = NULL;
	try
	{
		Intern someRandomIntern;
		Bureaucrat	exec("name", 1);

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		exec.signForm(*rrf);
		for (size_t i = 0; i < 5; i++)
			exec.executeForm(*rrf);
		delete rrf;	
	}
	catch(const std::exception& e)
	{
		delete rrf;
		std::cerr << e.what() << '\n';
	}
}
