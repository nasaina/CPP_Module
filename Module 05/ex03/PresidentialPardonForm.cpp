/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:26:56 by nandrian          #+#    #+#             */
/*   Updated: 2025/09/18 10:21:50 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("President", 25, 5), _target("Default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("President", 25, 5), _target(target)
{
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &other) const
{
	int	grade;

	grade = other.getGrade();
	if (this->getStatus() )
	{
		if (grade < this->getSign() && grade < this->getExec())
					   std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		else
			throw GradeTooLowException();
	}
	else
		throw NotSignedException();
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
