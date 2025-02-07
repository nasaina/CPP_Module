/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:18:36 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/05 07:35:58 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <unistd.h>

#include "Contact.hpp"

Contact::Contact()
{
	return ;
}

std::string	GetInput(std::string type)
{
	std::string	str;

	while (str.length() == 0)
	{
		std::cout << type;
		if (!std::getline(std::cin, str))
		{
			std::cin.clear();
			std::cin.ignore();	
			return (str.append(""));
		}
	}
	return (str);
}

void	CheckLen(std::string input)
{
	if (input.length() == 0)
		_exit(1);
}

void	Contact::SetId(int count)
{
	Id = count + 1;
}

void	Contact::SetFirstName(void)
{
	FirstName = GetInput("Enter first name : ");
	CheckLen(FirstName);
}

void	Contact::SetLastName(void)
{
	LastName = GetInput("Enter last name : ");
	CheckLen(LastName);
}

void	Contact::SetNickName(void)
{
	NickName = GetInput("Enter nick name : ");
	CheckLen(NickName);
}

void	Contact::SetDarkSecret(void)
{
	DarkSecret = GetInput("Enter dark secret : ");
	CheckLen(DarkSecret);
}

bool DigitCheck(std::string str)
{
	size_t	i;

	i = 0;
	while (i < str.length())
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void	Contact::SetNumber(void)
{
	std::string	input = "";
	while (input.length() == 0)
	{
		std::cout << "Enter number phone : ";
		if (!std::getline(std::cin, input))
		{
			std::cin.clear();
			std::cin.ignore();
			_exit(1);
		}
		if (!DigitCheck(input))
			input = "";
	}
	Number = input;
	CheckLen(Number);
	return ;
}

std::string	Trunc(std::string input)
{
	if (input.length() > 10)
	{
		return (input.substr(0, 9) + ".");
		input.resize(10);
	}
	return (input);
}

void	Contact::PrintId(void)
{
	std::cout << std::setw(10) << Id;
	return ;
}

int	Contact::GetId()
{
	int	id;

	id = Id;
	return (id);
}

void	Contact::PrintFirstName(void)
{
	std::cout << std::setw(10) << Trunc(FirstName);
	return ;
}

void	Contact::PrintLastName(void)
{
	std::cout << std::setw(10) << Trunc(LastName);
	return ;
}

void	Contact::PrintNickName(void)
{
	std::cout << std::setw(10) << Trunc(NickName);
	return ;
}

void	Contact::PrintDarkSecret(void)
{
	std::cout << std::setw(10) << Trunc(DarkSecret);
	return ;
}

void	Contact::PrintNumber(void)
{
	std::cout << std::setw(10) << Number;
	return ;
}

void	Contact::PrintAll(void)
{
	std::cout << "Id : " << Id << std::endl;
	std::cout << "First Name : " << FirstName << std::endl;
	std::cout << "Last Name : " << LastName << std::endl;
	std::cout << "Nick Name : " << NickName << std::endl;
	std::cout << "Dark Secret : " << DarkSecret << std::endl;
	std::cout << "Number : " << Number << std::endl;
}
