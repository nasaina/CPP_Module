/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:45:45 by nandrian          #+#    #+#             */
/*   Updated: 2025/06/24 17:05:16 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robot", 72, 45), _target("Default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robot", 72, 45), _target(target)
{
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &other) const
{
	int	grade;
	int	random;

	grade = other.getGrade();
	if (this->getStatus())
	{
		if (grade < this->getSign() && grade < this->getExec())
		{
			random = rand() % 2;
			std::cout << "jzzzzzzzzz" << std::endl;
			if (random != 0)
				std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
			else
				std::cout << "The robotomy failed." << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else
		throw NotSignedException();
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
