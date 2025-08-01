/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:34:33 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/04 15:37:18 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::Intern()
{
}

const char	*Intern::FormNotFound::what() const throw()
{
	return ((const char *)"There is no type of form found");
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	int	lvl;
	FormName	type[3] = {
		{"presidential pardon"},
		{"robotomy request"},
		{"shrubbery creation"},
	};

	for (size_t i = 0; i < 3; i++)
	{
		if (name == type[i].name)
			lvl = (int)i;
	}
	switch (lvl)
	{
		case 0:
		{
			std::cout << "Intern creates " << type[0].name << " Form" << std::endl;
			return (new PresidentialPardonForm(target));
			break;
		}
		case 1:
		{
			std::cout << "Intern creates " << type[1].name << " Form" << std::endl;
			return (new RobotomyRequestForm(target));
			break;
		}
		case 2:
		{
			std::cout << "Intern creates " << type[2].name << " Form" << std::endl;
			return (new ShrubberyCreationForm(target));
			break;
		}
		default:
		{
			throw	FormNotFound();
			break;
		}
	}
}

Intern::~Intern()
{
}
