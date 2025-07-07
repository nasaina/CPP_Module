/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:45:45 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/07 10:18:07 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		std::string	getTarget(void) const;
		void	execute(Bureaucrat const &other) const;
		~RobotomyRequestForm();
};

#endif