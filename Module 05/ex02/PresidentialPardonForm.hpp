/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:45:45 by nandrian          #+#    #+#             */
/*   Updated: 2025/06/24 17:23:44 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		std::string	getTarget(void) const;
		void	execute(Bureaucrat const &other) const;
		~PresidentialPardonForm();
};

#endif