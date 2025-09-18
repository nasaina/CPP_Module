/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:17:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/09/18 16:39:33 by nandrian         ###   ########.fr       */
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

std::string	trim(std::string const &input)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (i < input.length() && isspace(input[i]))
		i++;
	len = input.length();
	while (len > i && isspace(input[len]))
		len--;
	return (input.substr(i, len - i));
}

bool getValue(std::string const &input)
{
	char	*end;
	double	value;

	if (!input.length())
	{
		std::cout << "Error: no number entered." << std::endl;
		return (false);
	}
	if (input[input.length() - 1] == '.')
	{
		std::cout << "Error: bad number." << std::endl;
		return (false);
	}
	value = strtod(input.c_str(), &end);
	if (*end)
	{
		std::cout << "Error: bad number." << std::endl;
		return (false);
	}
	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

void findDate(list const &dates, std::string const &target, const std::string &value)
{
    std::string previous = "";
	list::const_iterator it = dates.begin();
	list::const_iterator out = it;


	it++;
    while (it != dates.end())
	{
		if (trim(it->first) <= target)
		{
			previous = trim(it->first);
			out = it;
		}
		it++;
    }
    if (previous.length())
	{
		std::cout << trim(target) << " => " << trim(value) << " => ";
		std::cout << std::atof(out->second.c_str()) * std::atof(value.c_str()) << std::endl;
	}
	else
		std::cout << "Error: no date referenced." << std::endl;
}

void	checkHeader(BitcoinExchange &data, BitcoinExchange &input)
{
	list content;

	content = input.getElement();
	if (trim(content.begin()->first) != "date" && trim(content.begin()->second) != "value")
		throw std::runtime_error("Error : head of your input file should be \"date | value\"");
	list dataElement = data.getElement();
	if (trim(dataElement.begin()->first) != "date" && trim(dataElement.begin()->second) != "exchange_rate")
		throw std::runtime_error("Error : head of your data file should be \"date,exchange_rate\"");
}

void	bitcoin(char **av)
{
	BitcoinExchange	data;
	BitcoinExchange	input((std::string)av[1]);

	list content = input.getElement();
	checkHeader(data, input);
	for (list::const_iterator it = content.begin(); it != content.end(); ++it) 
	{
		if (!getDate(it->first))
			std::cout << "Error: bad input => " << it->first << std::endl;
		else
		{
			if (!getValue(trim(it->second)))
				continue ;
			findDate(data.getElement(), trim(it->first), trim(it->second));
		}
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			std::cout << "Starting Bitcoin Exchange test..." << std::endl;
			bitcoin(av);
			std::cout << "Test completed successfully!" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Test failed: " << e.what() << std::endl;
			return (1);
		}
	}
	else
	{
		std::cout << "Test failed: Usage: ./btc [input_file]" << std::endl;
		return (1);
	}
	std::cout << "All tests passed!" << std::endl;
	return (0);
}
