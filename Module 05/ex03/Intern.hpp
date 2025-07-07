/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:12:50 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/04 15:37:42 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Form.h"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"


class Intern
{
	private:
		
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		class	FormNotFound : public std::exception
		{
			virtual const char	*what() const throw();
		};
		~Intern();
		AForm	*makeForm(std::string name, std::string target);
};

#endif