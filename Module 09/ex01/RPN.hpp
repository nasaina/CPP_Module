/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 08:16:41 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/29 11:09:32 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstring>
# include <cstdlib>
# include <exception>
# include <map>

class RPN
{
	private:
		std::string		_operators;
		std::stack<int> _element;
		bool			checkArgs(std::string const &av);
		void			insertElement(std::string const &av);
		int				operation(int a, int b);
		void			makeOperation(void);
		int				getElement(void) const;
		RPN();
		RPN(RPN const &other);
		RPN	&operator=(RPN const &other);
	public:
		RPN(std::string const &av);
		~RPN();
};

bool	RPN::checkArgs(std::string const &av)
{
	// int 	count;
	std::map<std::string, std::string>	tmp;
	size_t	i;
	size_t	j;
	// size_t	last;

	// count = 0;
	i = 0;
	j = 0;
	// while (i < av.length() && j < av.length())
	// {
	while (!std::strchr("+*/-", av[i]))
		i++;
	// last = i;
	j = i + 1;
	while (std::strchr("+-*/", av[j]) || isspace(av[j]))
		j++;
	tmp.insert(std::pair<std::string, std::string>(av.substr(0, i), av.substr(j, j - i)));
	std::cout << tmp.begin()->first << "endl " << tmp.begin()->second << std::endl;
		
	// }
	
	
	// while (count < 3)
	// {
	// 	while (isspace(av[i]))
	// 		i++;
	// 	if (!isdigit(av[i]))
	// 		return (false);
	// 	count++;
	// }
	// for (i = i; i < av.length(); i++)
	// {
	// 	while (isspace(av[i]))
	// 		i++;
	// 	count++;
	// 	if (count % 2 && !isdigit(av[i]))
	// 		return (false);
	// 	else if (!count % 2 && std::strchr("+-*/", av[i]))
	// 		return (false);
	// }
	return (true);
}

RPN	&RPN::operator=(RPN const &other)
{
	_operators = other._operators;
	_element = other._element;
	return (*this);
}

int	RPN::operation(int a, int b)
{
	if (_operators == "+")
		return (a + b);
	else if (_operators == "-")
		return (a - b);
	else if (_operators == "*")
		return (a * b);
	else if (_operators == "/")
		return (a / b);
	throw	std::runtime_error("Error");
	return (-1);
}

int	RPN::getElement(void) const
{
	return (_element.top());
}

void	RPN::makeOperation()
{
	int	a;
	int	b;

	a = _element.top();
	_element.pop();
	b = _element.top();
	_element.pop();
	_element.push(operation(b, a));
}

void	RPN::insertElement(std::string const &av)
{
	size_t	i;
	std::stack<std::string>	tmp;

	i = 0;
	while (isspace(av[i]))
		i++;
	tmp.push(av.substr(i, 1));
	_element.push(std::atoi(tmp.top().c_str()));
	tmp.pop();
	i++;
	while (i < av.length())
	{
		while (isspace(av[i]))
			i++;
		tmp.push(av.substr(i, 1));
		_element.push(std::atoi(tmp.top().c_str()));
		tmp.pop();
		i++;
		while (isspace(av[i]))
			i++;
		tmp.push(av.substr(i, 1));
		_operators = tmp.top();
		tmp.pop();
		makeOperation();
		i++;
	}
}

RPN::RPN(std::string const &av)
{
	if (checkArgs(av))
	{
		insertElement(av);
		std::cout << getElement() << std::endl;
	}
	else
		std::cerr << "Error" << std::endl;
}

RPN::~RPN()
{
}

#endif