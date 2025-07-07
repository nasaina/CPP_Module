/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:17:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/07 10:27:29 by nandrian         ###   ########.fr       */
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

	std::cout << "Number : " << random << std::endl;
	if (random == 0)
		return (new A);
	if (random == 1)
		return (new B);
	return (new C);
}

void identify(Base* p)
{
	Base *a = dynamic_cast<A *>(p);
	Base *b = dynamic_cast<B *>(p);
	Base *c = dynamic_cast<C *>(p);
	if (a)
		std::cout << "Type is A" << std::endl;
	if (b)
		std::cout << "Type is B" << std::endl;
	if (c)
		std::cout << "Type is C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "Type is A" << std::endl;
	}
	catch(const std::exception& e)
	{
		(void)e;
		try
		{
			dynamic_cast<B &>(p);
			std::cout << "Type is B" << std::endl;
		}
		catch(const std::exception& e)
		{
			(void)e;
			try
			{
				dynamic_cast<C &>(p);
				std::cout << "Type is C" << std::endl;
			}
			catch(const std::exception& e)
			{
				(void)e;
			}
		}
	}	
}

int	main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	for (size_t i = 1; i < 10; i++)
	{
		Base *p = generate();
		Base &r = *p;

		std::cout << "test number : " << i << std::endl;
		identify(p);
		identify(r);
		std::cout << std::endl;
		delete p;
	}
	return (0);
}