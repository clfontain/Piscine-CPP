/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:16:27 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/15 12:07:01 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Contact.hpp"
#include "./includes/Phonebook.hpp"

int Contact::set_first_name(std::string &first_name)
{
	this->_first_name = first_name; 
	return(0);
}

std::string Contact::get_first_name( void ) const
{
	return(_first_name);
}

int Contact::set_last_name(std::string &last_name)
{
	this->_last_name = last_name; 
	return(0);
}

std::string Contact::get_last_name( void ) const
{
	
	return(_last_name);
}

int Contact::set_nick_name(std::string &nick_name)
{
	this->_nick_name = nick_name; 
	return(0);
}

std::string Contact::get_nick_name( void ) const
{
	
	return(_nick_name);
}

int Contact::set_phone_number(std::string &phone_number)
{
	this->_phone_number = phone_number; 
	return(0);
}

std::string Contact::get_phone_number( void ) const
{
	
	return(_phone_number);
}


int Contact::set_darkest_secret(std::string &darkest_secret)
{
	this->_darkest_secret = darkest_secret; 
	return(0);
}

std::string Contact::get_darkest_secret( void ) const
{
	return(_darkest_secret);
}



Contact::Contact( void) 
{
	return;
}

Contact::~Contact( void ) 
{
	
}

