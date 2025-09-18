/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:17:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/09/18 16:18:08 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

Base* generate(void)
{
	int	random = rand() % 3;

	if (random == 0)
		return (new A);
	if (random == 1)
		return (new B);
	return (new C);
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Type is A";
	else if (dynamic_cast<B *>(p))
		std::cout << "Type is B";
	else if (dynamic_cast<C *>(p))
		std::cout << "Type is C";
	else
		std::cout << "Unknown type";
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "Type is A";
		return;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	
	try
	{
		dynamic_cast<B &>(p);
		std::cout << "Type is B";
		return;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	
	try
	{
		dynamic_cast<C &>(p);
		std::cout << "Type is C";
		return;
	}
	catch(const std::exception& e)
	{
		(void)e;
		std::cout << "Unknown type";
	}
}

int	main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	
	std::cout << "Testing Base class type identification:" << std::endl << std::endl;

	std::cout << "--- Random generation tests ---" << std::endl;
	for (size_t i = 1; i <= 10; i++)
	{
		Base *p = generate();
		Base &r = *p;

		std::cout << "Test " << i << " - Pointer identification: ";
		identify(p);
		std::cout << " | Reference identification: ";
		identify(r);
		std::cout << std::endl;
		delete p;
	}
	std::cout << std::endl;

	std::cout << "--- Specific type tests ---" << std::endl;
	
	Base *aPtr = new A;
	Base *bPtr = new B;
	Base *cPtr = new C;
	
	std::cout << "Testing A class - Pointer: ";
	identify(aPtr);
	std::cout << " | Reference: ";
	identify(*aPtr);
	std::cout << std::endl;
	
	std::cout << "Testing B class - Pointer: ";
	identify(bPtr);
	std::cout << " | Reference: ";
	identify(*bPtr);
	std::cout << std::endl;
	
	std::cout << "Testing C class - Pointer: ";
	identify(cPtr);
	std::cout << " | Reference: ";
	identify(*cPtr);
	std::cout << std::endl;
	
	delete aPtr;
	delete bPtr;
	delete cPtr;
	
	std::cout << std::endl;
	std::cout << "--- NULL pointer test ---" << std::endl;
	Base *nullPtr = NULL;
	std::cout << "Testing NULL pointer: ";
	identify(nullPtr);
	std::cout << std::endl;
	
	std::cout << std::endl << "All type identification tests completed!" << std::endl;
	
	return (0);
}
