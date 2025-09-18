/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:39:22 by nandrian          #+#    #+#             */
/*   Updated: 2025/09/18 09:57:47 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_status;
		const int			_sign;
		const int			_exec;
	public:
		AForm();
		AForm(std::string name, int sign, int exec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);

		class	GradeTooHighException : public std::exception
		{
			virtual const char	*what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			virtual const char	*what() const throw();
		};
		class	NotSignedException : public std::exception
		{
			virtual const char	*what() const throw();
		};

		void				beSigned(Bureaucrat &other);
		
		std::string			getName(void) const;
		bool				getStatus(void) const;
		int					getSign(void) const;
		int					getExec(void) const;
		virtual void		execute(Bureaucrat const &executor) const = 0;
		virtual ~AForm();
};


std::ostream	&operator<<(std::ostream &os, const AForm &other);

#endif