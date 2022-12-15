/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   My_Awesome_PhoneBook.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:33:37 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/16 10:55:21 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Contact.hpp"
#include "./includes/Phonebook.hpp"

int main() 
{
	PhoneBook phonebook;
	std::string prompt;
	int i;
	i = 0;
	while (prompt.compare("EXIT") != 0)
	{
		std::cout << "Welcome to your awesome PhoneBook" << std::endl;
		std::cout << "Enter ADD, SEARCH or EXIT" << std::endl;
		std::getline (std::cin, prompt);
		if (std::cin.eof() == true)
			exit(1);
		if (prompt.compare("ADD") == 0)
			phonebook.add_contact();
		if (prompt.compare("SEARCH") == 0)
		{
			phonebook.print_tab_contact();
			std::cout << "Enter index" << std::endl;
			std::getline (std::cin, prompt);
			if (std::cin.eof() == true)
				exit(1);
			i = atoi(prompt.c_str());
			if (i <= 0 || i > 8 || strlen(prompt.c_str()) != 1)
			{
				std::cout << "Error index" << std::endl;
				continue;
			}
			else
				phonebook.print_contact(i - 1);
		}	
	}
	return (0);
}