/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:17:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/28 11:25:26 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	verifyDate(int year, int month, int day)
{
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	if (month % 2 == 0 && month <= 7 && day > 30)
		return (false);
	else if (month % 2 != 0 && month > 7 && day > 30)
		return (false);
	if (month == 2 && year % 4 != 0 && day > 28)
		return (false);
	else if (month == 2 && day > 29)
		return (false);
	return (true);
}

bool getDate(std::string const &input)
{
	std::string	date;

	date = input.substr(0, 10);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!isdigit(date[i]))
			return (false);
	}
	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	return (verifyDate(year, month, day));
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			BitcoinExchange	data;
			BitcoinExchange	input((std::string)av[1]);
			list			contain;
			
			std::cout << "---- data ----\n";
			contain = data.getElement();
			for (list::const_iterator it = contain.begin(); it != contain.end(); ++it) 
			{
				getDate(it->first);
				// if (dateCheck(it->first))
				// 	std::cout << it->first << std::endl;
			}
			std::cout << "\n---- input ----\n";
			list content = input.getElement();
			for (list::const_iterator it = content.begin(); it != content.end(); ++it) 
			{
				getDate(it->first);
				// if (dateCheck(it->first))
				// 	std::cout << it->first << " | ";
				// if (getValue(it->second) != -1)
				// 	std::cout << it->second << std::endl;
				// else
				// 	std::cout << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	return 0;
}
