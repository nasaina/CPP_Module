/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:55:56 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/10 11:33:57 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "Fonction.hpp"

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
	std::cout << "this is a debug" << std::endl;
}
void	Harl::info(void)
{
	std::cout << "this is an info" << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "this is a warning" << std::endl;
}
void	Harl::error(void)
{
	std::cout << "this is an error" << std::endl;
}

void	Harl::complain(std::string level)
{
	Function function[4] = {
		{"debug", &Harl::debug},
		{"info", &Harl::info},
		{"warning", &Harl::warning},
		{"error", &Harl::error},
	};


	for (size_t i = 0; i < sizeof(function) / sizeof(function[0]); i++)
	{
		Function& f = function[i];
		if (level == f.Name) {
			(this->*f.functions)();
			return;
		}
	}
}
