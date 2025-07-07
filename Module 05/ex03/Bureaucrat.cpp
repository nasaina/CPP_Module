/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:36:55 by nandrian          #+#    #+#             */
/*   Updated: 2025/06/27 11:14:10 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade > 150)
		throw GradeTooLowException();
	else if (_grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()), _grade(other.getGrade())
{
}

void	Bureaucrat::executeForm(AForm const & form) const
{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
}

void	Bureaucrat::signForm(AForm &other)
{
	try
	{
		other.beSigned(*this);
		std::cout << this->getName() << " signed " << other.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << other.getName() << " because " << e.what() << std::endl;
	}
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	(std::string)_name = other.getName();
	_grade = other.getGrade();
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ((const char *)"Higher grade reached");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ((const char *)"Lower grade reached");
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementation(void)
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementation(void)
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

Bureaucrat::~Bureaucrat()
{
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &other)
{
	os << other.getName() << ", bureaucrat grade" << other.getGrade() << ".";
	return (os);
}
