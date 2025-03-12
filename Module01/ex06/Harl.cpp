/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:55:56 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/12 07:04:44 by nandrian         ###   ########.fr       */
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
	<< "I just need some attention from you" << std::endl << std::endl;
}
void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl
	<< "We can talk, play, eat. That will please me." << std::endl << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl
	<< "If you don't do this, we may break up." << std::endl << std::endl;
}
void	Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl
	<< "No, I think it's over." << std::endl << std::endl;
}

void	Harl::complain(std::string level)
{
	int			Type = 0;
	Function	f;
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
			Type = i + 1;
			break;
		}
	}
	switch (Type)
	{
		case 1:
			for (size_t i = 0; i < 4; i++)
			{
				f = function[i];
				(this->*f.functions)();
			}
			break;
		case 2:
			for (size_t i = 1; i < 4; i++)
			{
				f = function[i];
				(this->*f.functions)();
			}
			break;
		case 3:
			for (size_t i = 2; i < 4; i++)
			{
				f = function[i];
				(this->*f.functions)();
			}
			break;
		case 4:
			for (size_t i = 3; i < 4; i++)
			{
				f = function[i];
				(this->*f.functions)();
			}
			break;
		default:
			std::cout << "[Probably complaining about insificant problems]" << std::endl;
			break;
	}
}
