/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:44:38 by nandrian          #+#    #+#             */
/*   Updated: 2025/03/11 14:37:28 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>

std::string	appendStr(std::string content, char **av)
{
	size_t		posFind;
	size_t		posActual = 0;
	std::string	toReplace(av[2]);
	std::string	result;
	std::string	replace = av[3];

	if (!av[2][0])
		return (content);
	while (posActual < content.length())
	{
		posFind = content.find(av[2], posActual);
		if (posFind != std::string::npos)
		{
			result.append(content, posActual, posFind - posActual);
			result.append(replace);
			posActual = posFind + toReplace.length();
		}
		else
		{
			result.append(content.substr(posActual));
			break ;
		}
	}
	return (result);
}

std::string	getContent(char **av)
{
	std::string	content;
	std::string	result;
	std::string	str;
	std::string	newLine = "\n";

	std::fstream file(av[1], std::ios::in);
	if (!file)
	{
		std::cout << "File not opened !" << std::endl;
		return (NULL);
	}
	else
	{
		while (std::getline(file, content))
		{
			result = appendStr(content, av);
			str += result;
			str += newLine;
		}
		return (str);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	std::string	filename;
	std::string	newContent;
	std::string	replace = ".replace";
	std::ofstream	newfile;

	if (ac == 4)	
	{
		std::fstream file(av[1], std::ios::in);
		if (!file)
		{
			std::cout << "File not opened !" << std::endl;
			return (1);
		}
		file.close();
		std::string	content;
		filename = av[1] + replace;
		const	char* str = filename.c_str();
		newfile.open(str, std::ios::out | std::ios::trunc);
		if (!newfile)
		{
			std::cout << "File not opened !" << std::endl;
			return (1);
		}
		else
		{
			newContent = getContent(av);
			newfile << newContent;
			newfile.close();
		}
	}
	else
		std::cout << "parameters required : filename, to_replace, for_replace" << std::endl;
	return (0);
}
