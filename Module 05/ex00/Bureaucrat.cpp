/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:36:55 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/07 09:49:39 by nandrian         ###   ########.fr       */
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

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
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
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return (os);
}
