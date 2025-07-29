/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 08:16:41 by nandrian          #+#    #+#             */
/*   Updated: 2025/07/29 14:50:16 by nandrian         ###   ########.fr       */
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

typedef std::map<std::string, std::string>	map;

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
		bool			checkString(std::string const &first, std::string const &second, size_t status);
		RPN();
		RPN(RPN const &other);
		RPN	&operator=(RPN const &other);
	public:
		RPN(std::string const &av);
		~RPN();
};

#endif
