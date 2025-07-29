/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 08:15:03 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/29 08:15:54 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

list	&BitcoinExchange::getElement(void) const
{
	return ((list &)_element);
}

BitcoinExchange::BitcoinExchange()
{
	std::fstream	fs;
	std::string		date;
	std::string		value;
	std::string		filename = "data.csv";

	fs.open(filename.c_str(), std::ios::in);
	if (!fs)
		throw std::runtime_error("Error: could not open file.");
	std::string line;
    while (std::getline(fs, line))
	{
        std::stringstream	ss(line);
        std::string			first;
        std::string			second;

        if (std::getline(ss, first, ',') && std::getline(ss, second))
			_element.push_back(std::make_pair(first, second));
    }
	fs.close();
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	std::fstream	fs;
	std::string		date;
	std::string		value;

	fs.open(filename.c_str(), std::ios::in);
	if (!fs)
		throw std::runtime_error("Error: could not open file.");
	std::string line;
	std::getline(fs, line);
    while (std::getline(fs, line))
	{
        std::stringstream	ss(line);
        std::string			first;
        std::string			second;

		if (std::getline(ss, first, '|'))
		{
			if (std::getline(ss, second))
				_element.push_back(std::make_pair(first, second));
			else
				_element.push_back(std::make_pair(first, ""));
		}
    }
	fs.close();
}

BitcoinExchange::~BitcoinExchange()
{
}
