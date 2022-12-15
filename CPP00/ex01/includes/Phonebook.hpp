/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:10:20 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/15 15:15:59 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	 PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

	public:

		PhoneBook( void );
		~PhoneBook( void );
		void add_contact(void);
		void print_tab_contact() const;
		void print_contact(int index) const;

	private:

		std::string add_info(const char * str);
		void print_string(std::string contact_info) const;
		int		_index;
		int		_total;
		Contact _contact[8];	

};

#endif