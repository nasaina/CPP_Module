/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:17:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/09/18 16:35:32 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "=== Basic Span tests ===" << std::endl;
	try
	{
		Span sp = Span(5);
		std::vector<int> v(3);

		v[0] = 21;
		v[1] = 12;
		v[2] = 43;
		sp.addNumber(10);
		sp.addNumber(0);
		sp.fillRange(v.begin(), v.end());
		
		std::cout << "Numbers in span: ";
		std::vector<int> numbers = sp.getNumbers();
		for (size_t i = 0; i < numbers.size(); i++)
			std::cout << numbers[i] << " ";
		std::cout << std::endl;
		
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing edge cases ===" << std::endl;
	try
	{
		// Test with only one element
		Span sp1(1);
		sp1.addNumber(42);
		std::cout << "Span with one element - shortest: " << sp1.shortestSpan() << std::endl;
		std::cout << "Span with one element - longest: " << sp1.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception with one element: " << e.what() << std::endl;
	}

	try
	{
		// Test with empty span
		Span sp2(1);
		std::cout << "Empty span - shortest: " << sp2.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception with empty span: " << e.what() << std::endl;
	}

	try
	{
		// Test overflow
		Span sp3(2);
		sp3.addNumber(1);
		sp3.addNumber(2);
		sp3.addNumber(3); // This should throw
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception with overflow: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing large span ===" << std::endl;
	try
	{
		Span largeSp(10000);
		std::vector<int> largeVec;
		
		// Fill with random numbers
		for (int i = 0; i < 10000; i++)
			largeVec.push_back(i * 2); // Even numbers
		
		largeSp.fillRange(largeVec.begin(), largeVec.end());
		
		std::cout << "Large span shortest: " << largeSp.shortestSpan() << std::endl;
		std::cout << "Large span longest: " << largeSp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception with large span: " << e.what() << std::endl;
	}

	return 0;
}