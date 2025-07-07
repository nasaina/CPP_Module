/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:36:04 by nandrian          #+#    #+#             */
/*   Updated: 2025/06/24 16:39:48 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char	*Form::GradeTooHighException::what() const throw()
{
	return ((const char *)"Highest grade reached");	
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ((const char *)"Lowest grade reached");
}

void	Form::beSigned(Bureaucrat &other)
{
	if (other.getGrade() <= this->getSign())
		_status = true;
	else
		throw GradeTooLowException();
}

Form::Form() : _name("Default"), _status(false), _sign(150), _exec(150)
{
}

Form::Form(const Form &other) : _name(other.getName()), _status(other.getStatus()), _sign(other.getStatus()), _exec(other.getExec())
{
}

Form &Form::operator=(const Form &other)
{
	this->_status = other.getStatus();
	return (*this);
}

Form::Form(std::string name, int sign, int exec) : _name(name), _status(false), _sign(sign), _exec(exec)
{
	if (sign < 1 || exec < 1)
		throw	GradeTooHighException();
	else if (sign > 150 || exec > 150)
		throw GradeTooLowException();
}

std::string	Form::getName(void) const
{
	return (_name);
}

bool	Form::getStatus(void) const
{
	return (_status);
}

int	Form::getSign(void) const
{
	return (_sign);
}

int	Form::getExec(void) const
{
	return (_exec);
}

std::ostream	&operator<<(std::ostream &os, const Form &other)
{
	std::string	status;

	if (other.getStatus())
		status = "is signed";
	else
		status = "is not signed";
	os << other.getName() << ", Form " << status << ", sign grade : "
		<< other.getSign() << ", exec grade : " << other.getExec();
	return (os);
}

Form::~Form()
{
}
