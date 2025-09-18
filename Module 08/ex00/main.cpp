/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:17:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/09/18 16:35:31 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main( void )
{
	std::cout << "=== Testing easyfind with std::vector ===" << std::endl;
	
	try
	{
		// Test with vector
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(42);
		vec.push_back(89);
		vec.push_back(100);
		vec.push_back(200);

		std::cout << "Vector contains: ";
		for (size_t i = 0; i < vec.size(); i++)
			std::cout << vec[i] << " ";
		std::cout << std::endl;

		// Test finding existing element
		std::cout << "Searching for 89: " << *::easyfind(vec, 89) << std::endl;
		std::cout << "Searching for 42: " << *::easyfind(vec, 42) << std::endl;
		
		// Test finding non-existing element
		std::cout << "Searching for 999: ";
		std::cout << *::easyfind(vec, 999) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing easyfind with std::list ===" << std::endl;
	
	try
	{
		// Test with list
		std::list<int> lst;
		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);
		lst.push_back(40);

		std::cout << "List contains: ";
		for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		// Test finding existing element
		std::cout << "Searching for 30: " << *::easyfind(lst, 30) << std::endl;
		
		// Test finding non-existing element
		std::cout << "Searching for 50: ";
		std::cout << *::easyfind(lst, 50) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing easyfind with std::deque ===" << std::endl;
	
	try
	{
		// Test with deque
		std::deque<int> deq;
		deq.push_back(5);
		deq.push_back(15);
		deq.push_back(25);

		std::cout << "Deque contains: ";
		for (size_t i = 0; i < deq.size(); i++)
			std::cout << deq[i] << " ";
		std::cout << std::endl;

		// Test finding existing element
		std::cout << "Searching for 15: " << *::easyfind(deq, 15) << std::endl;
		
		// Test empty container
		std::deque<int> empty_deq;
		std::cout << "Searching in empty deque: ";
		std::cout << *::easyfind(empty_deq, 1) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}
