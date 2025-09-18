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

#include "RPN.hpp"

int main(int argc, char const *av[])
{
	if (argc == 2)
	{
		try
		{
			std::cout << "Starting RPN calculator test..." << std::endl;
			RPN((std::string const)av[1]);
			std::cout << "RPN calculation completed successfully!" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Test failed: " << e.what() << std::endl;
			return (1);
		}
	}
	else
	{
		std::cerr << "Test failed: Usage: ./RPN [expression]" << std::endl;
		return (1);
	}
	std::cout << "All tests passed!" << std::endl;
	return (0);
}
