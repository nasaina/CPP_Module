/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:36:04 by nandrian          #+#    #+#             */
/*   Updated: 2025/06/27 11:19:52 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ((const char *)"Highest grade reached");	
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ((const char *)"Lowest grade reached");
}

const char	*AForm::NotSignedException::what() const throw()
{
	return ((const char *)"Form is not signed");
}

void	AForm::beSigned(Bureaucrat &other)
{
	if (other.getGrade() <= this->getSign())
		_status = true;
	else
		throw GradeTooLowException();
}

AForm::AForm() : _name("Default"), _status(false), _sign(150), _exec(150)
{
}

AForm::AForm(const AForm &other) : _name(other.getName()), _status(other.getStatus()), _sign(other.getStatus()), _exec(other.getExec())
{
}

AForm &AForm::operator=(const AForm &other)
{
	this->_status = other.getStatus();
	return (*this);
}

AForm::AForm(std::string name, int sign, int exec) : _name(name), _status(false), _sign(sign), _exec(exec)
{
	if (sign < 1 || exec < 1)
		throw	GradeTooHighException();
	else if (sign > 150 || exec > 150)
		throw GradeTooLowException();
}

std::string	AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getStatus(void) const
{
	return (_status);
}

int	AForm::getSign(void) const
{
	return (_sign);
}

int	AForm::getExec(void) const
{
	return (_exec);
}

std::ostream	&operator<<(std::ostream &os, const AForm &other)
{
	std::string	status;

	if (other.getStatus())
		status = "is signed";
	else
		status = "is not signed";
	os << other.getName() << ", AForm " << status << ", sign grade : "
		<< other.getSign() << ", exec grade : " << other.getExec();
	return (os);
}

AForm::~AForm()
{
}
