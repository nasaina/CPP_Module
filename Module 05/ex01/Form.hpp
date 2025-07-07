/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:39:22 by nandrian          #+#    #+#             */
/*   Updated: 2025/06/24 16:39:35 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_status;
		const int			_sign;
		const int			_exec;
	public:
		Form();
		Form(std::string name, int sign, int exec);
		Form(const Form &other);
		Form &operator=(const Form &other);

		class	GradeTooHighException : public std::exception
		{
			virtual const char	*what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			virtual const char	*what() const throw();
		};

		void	beSigned(Bureaucrat &other);

		std::string	getName(void) const;
		bool		getStatus(void) const;
		int			getSign(void) const;
		int			getExec(void) const;
		~Form();
};

std::ostream	&operator<<(std::ostream &os, const Form &other);

#endif