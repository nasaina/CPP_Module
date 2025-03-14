/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:55:56 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/12 07:03:06 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "Function.hpp"

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
	return ;
}
void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl
	<< "I just need some attention from you" << std::endl;
}
void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl
	<< "We can talk, play, eat. That will please me." << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl
	<< "If you don't do this, we may break up." << std::endl;
}
void	Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl
	<< "No, it's over." << std::endl;
}

void	Harl::complain(std::string level)
{
	Function function[4] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error},
	};

	for (size_t i = 0; i < 4; i++)
	{
		Function& f = function[i];
		if (level == f.Name) {
			(this->*f.functions)();
			return;
		}
	}
	std::cout << "[Probably complaining about insificant problems]" << std::endl;
}
