/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:17:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/09/18 14:50:07 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(void)
{
	std::cout << "Testing ScalarConverter with various inputs:" << std::endl << std::endl;

	std::cout << "--- Testing char literals ---" << std::endl;
	ScalarConverter::convert("a");
	std::cout << std::endl;
	ScalarConverter::convert("Z");
	std::cout << std::endl;
	ScalarConverter::convert("'x'");
	std::cout << std::endl;

	std::cout << "--- Testing int literals ---" << std::endl;
	ScalarConverter::convert("42");
	std::cout << std::endl;
	ScalarConverter::convert("-42");
	std::cout << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;
	ScalarConverter::convert("2147483647");
	std::cout << std::endl;
	ScalarConverter::convert("-2147483648");
	std::cout << std::endl;

	std::cout << "--- Testing float literals ---" << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << std::endl;
	ScalarConverter::convert("-42.42f");
	std::cout << std::endl;
	ScalarConverter::convert("0.0f");
	std::cout << std::endl;

	std::cout << "--- Testing double literals ---" << std::endl;
	ScalarConverter::convert("42.0");
	std::cout << std::endl;
	ScalarConverter::convert("-42.42");
	std::cout << std::endl;
	ScalarConverter::convert("0.0");
	std::cout << std::endl;

	std::cout << "--- Testing special values ---" << std::endl;
	ScalarConverter::convert("inf");
	std::cout << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << std::endl;
	ScalarConverter::convert("inff");
	std::cout << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << std::endl;

	std::cout << "--- Testing invalid inputs ---" << std::endl;
	ScalarConverter::convert("abc");
	std::cout << std::endl;
	ScalarConverter::convert("42.42.42");
	std::cout << std::endl;
	ScalarConverter::convert("");
	std::cout << std::endl;

	return (0);
}