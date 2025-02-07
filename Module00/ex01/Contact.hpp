/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandrian <nandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:21:08 by nandrian          #+#    #+#             */
/*   Updated: 2025/02/03 09:33:15 by nandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		int			Id;
		std::string	Number;
		std::string	FirstName;
		std::string	LastName;
		std::string	NickName;
		std::string	DarkSecret;

	public:
		Contact(void);

		void	SetId(int count);
		void	SetFirstName(void);
		void	SetLastName(void);
		void	SetNickName(void);
		void	SetDarkSecret(void);
		void	SetNumber(void);

		void	PrintId(void);
		void	PrintFirstName(void);
		void	PrintLastName(void);
		void	PrintNickName(void);
		void	PrintDarkSecret(void);
		void	PrintNumber(void);
		void	PrintAll(void);
		int		GetId(void);
};

#endif