/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:17:25 by nandrian          #+#    #+#             */
/*   Updated: 2025/09/18 16:35:37 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void)
{
	std::cout << "=== Testing MutantStack ===" << std::endl;
	
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Top element: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	std::cout << "Final size: " << mstack.size() << std::endl;
	
	std::cout << "Iterating through MutantStack:" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	// Test copy constructor
	std::stack<int> s(mstack);
	std::cout << "Copied stack size: " << s.size() << std::endl;

	std::cout << "\n=== Comparing with std::list ===" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	lst.pop_back();
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	
	std::cout << "List contents:" << std::endl;
	for (std::list<int>::iterator it_list = lst.begin(); it_list != lst.end(); ++it_list)
		std::cout << *it_list << std::endl;

	std::cout << "\n=== Testing different types ===" << std::endl;
	MutantStack<std::string> stringStack;
	stringStack.push("Hello");
	stringStack.push("World");
	stringStack.push("42");
	
	std::cout << "String stack contents:" << std::endl;
	for (MutantStack<std::string>::iterator str_it = stringStack.begin(); 
		 str_it != stringStack.end(); ++str_it)
		std::cout << *str_it << std::endl;

	std::cout << "\n=== Testing empty stack ===" << std::endl;
	MutantStack<int> emptyStack;
	std::cout << "Empty stack size: " << emptyStack.size() << std::endl;
	
	if (emptyStack.begin() == emptyStack.end())
		std::cout << "Empty stack: begin == end" << std::endl;
	
	return 0;
}
