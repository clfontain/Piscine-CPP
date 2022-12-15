/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:10:20 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/15 16:43:41 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	 CONTACT_HPP
# define CONTACT_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>

class Contact {

	public:

		Contact ( void );
		~Contact ( void );

	int set_first_name(std::string &first_name);
	int set_last_name(std::string &last_name);
	int set_nick_name(std::string &nickname);
	int set_phone_number(std::string &phone_number);
	int set_darkest_secret(std::string &darkest_secret);

	std::string get_first_name( void ) const;
	std::string get_last_name( void ) const;
	std::string get_nick_name( void ) const;
	std::string get_phone_number( void ) const;
	std::string get_darkest_secret( void ) const;

	private:

	std::string _first_name;
	std::string _last_name;
	std::string _nick_name;
	std::string _phone_number;
	std::string _darkest_secret;	
};

#endif