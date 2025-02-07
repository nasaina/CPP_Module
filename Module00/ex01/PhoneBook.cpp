/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:22:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/03 09:35:55 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
#include "Contact.hpp"
#include "PhoneBook.hpp"

bool	DigitCheck(std::string input);

PhoneBook::PhoneBook()
{
	count = 0;
	size = 0;
	first = 0;
}

Contact	InsertContact(int count)
{
	Contact	contacts;

	contacts.SetId(count);
	contacts.SetFirstName();
	contacts.SetLastName();
	contacts.SetNickName();
	contacts.SetDarkSecret();
	contacts.SetNumber();
	return (contacts);
}

void	Swap(Contact *contact)
{
	int		i;
	Contact tmp;

	tmp = contact[0];
	contact[0] = contact[1];
	contact[0].SetId(0);
	i = 1;
	while (i + 1 < 8)
	{
		contact[i] = contact[i + 1];
		contact[i].SetId(i);
		i++;
	}
	contact[i] = tmp;
}

void	PhoneBook::AddContact()
{
	static int i;

	if (i < 8)
	{
		Contacts[i] = InsertContact(i);
		i++;
		size = i;
	}
	else
	{
		Contacts[0] = InsertContact(7);
		Swap(Contacts);
		i++;
		size = 8;
	}
	return ;
}

void	Header(void)
{
	std::cout << std::setw(10) << "Id";
	std::cout << "| ";
	std::cout << std::setw(10) << "First Name";
	std::cout << "| ";
	std::cout << std::setw(10) << "Last Name";
	std::cout << "| ";
	std::cout << std::setw(10) << "Nick Name";
	std::cout << "| " << std::endl;
}

int	FindId(void)
{
	int			Id;
	const char	*str;
	std::string input;

	input = "";
	while (input.length() == 0)
	{
		std::cout << "Enter ID [1 - 8] : ";
		if (!std::getline(std::cin, input))
		{
			input.clear();
			_exit(1);
		}
		if (!DigitCheck(input))
		{
			input = "";
			continue ;
		}
		str = input.c_str();
		Id = atoi(str);
		if (Id < 1 || Id > 8)
			input = "";
	}
	return (Id);
}

void	PrintContact(int count, Contact *Contacts)
{
	Contacts[count].GetId();
	Contacts[count].PrintId();
	std::cout << "| ";
	Contacts[count].PrintFirstName();
	std::cout << "| ";
	Contacts[count].PrintLastName();
	std::cout << "| ";
	Contacts[count].PrintNickName();
	std::cout << "|" << std::endl;
}

void	PhoneBook::PrintContacts(void)
{
	int	Find;

	count = 0;
	if (size == 0)
	{
		std::cout << "ADD contact first" << std::endl;
		return ;
	}
	Header();
	while (count < size)
	{
		PrintContact(count, Contacts);
		count++;
	}
	while (1)
	{
		Find = FindId();
		count = 0;
		while (count < size)
		{
			int	Nb = Contacts[count].GetId();
			if (Find == Nb)
			{
				Contacts[count].PrintAll();
				return ;
			}
			count++;
		}
	}
	return ;
}
