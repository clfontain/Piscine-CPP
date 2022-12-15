/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:44:54 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/16 10:55:42 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Contact.hpp"
#include "./includes/Phonebook.hpp"

void	PhoneBook::print_string(std::string contact_info) const
{
	int n;
	std::string first_ten;
	n = 0;
	n = contact_info.length();
	if ( n > 10)
	{
		first_ten = contact_info.substr(0, 9);
		std::cout << std::right << first_ten;
		std::cout << ".";
	}
	else
	{
		std::cout << std::string((10 - n) , ' ');
		std::cout  << std::right << contact_info;
	}		
}

void PhoneBook::print_tab_contact() const
{
	int i = 0;
	while (i < _total)
	{
		std::cout << std::string(9 , ' ') << (i + 1) << "|";
		print_string(this->_contact[i].get_first_name());
		std::cout <<"|";
		print_string(this->_contact[i].get_last_name());
		std::cout <<"|";
		print_string(this->_contact[i].get_nick_name());
		std::cout <<"|";
		std::cout << std::endl;
		i++;
	}	
}

std::string PhoneBook::add_info(const char * str)
{
	std::string prompt;
	int i;
	i = 0;
	while (i == 0)
	{
		std::cout << "Enter " << str << std::endl;
		std::getline (std::cin, prompt);
		if (std::cin.eof() == true)
			exit(1);
		if (prompt.length() != 0)
		{
			std::cout << str << " is : " << prompt << std::endl;
			i++;
		}
		else
			std::cout << "Error, empty string" << std::endl;
	}
	return (prompt);
}

void	PhoneBook::add_contact( void)
{
	if (_index == 8)
		_index = 0;
	std::string info;
	info = this->add_info("First name");
	this->_contact[_index].set_first_name(info);
	info = this->add_info("Last name");
	this->_contact[_index].set_last_name(info);
	info = this->add_info("Nick name");
	this->_contact[_index].set_nick_name(info);
	info = this->add_info("Phone number");
	this->_contact[_index].set_phone_number(info);
	info = this->add_info("Darkest secret");
	this->_contact[_index].set_darkest_secret(info);
	if (_total < 8)
		_total++;
	_index++;
	return ;
}

void PhoneBook::print_contact(int index) const
{
	if (index >= _total)
	{
		std::cout << "Error invalid index "<< std::endl;
		return ;
	}	
	std::cout << "First name     " << this->_contact[index].get_first_name() << std::endl;
	std::cout << "Last name      " << this->_contact[index].get_last_name() << std::endl;
	std::cout << "Nick name      " << this->_contact[index].get_nick_name() << std::endl;
	std::cout << "Phone number   " << this->_contact[index].get_phone_number() << std::endl;
	std::cout << "Darkest secret " << this->_contact[index].get_darkest_secret() << std::endl;
}


PhoneBook::PhoneBook( void) {

	_index = 0;
	_total = 0;
	return;
}

PhoneBook::~PhoneBook( void )
{
	std::cout << "AU REVOIR" << std::endl;
}

