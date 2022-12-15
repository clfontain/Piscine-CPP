/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:42:19 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/21 10:55:12 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR;
	stringPTR = &str;
	std::string &stringREF = str;
	

	
	std::cout << "adresse in str       : "<< &str <<  std::endl;
	std::cout << "adresse in stringPTR : "<< &stringPTR << std::endl;
	std::cout << "adresse in stringREF : "<< &stringREF << std::endl;
	std::cout << "str                  : "<< str <<  std::endl;
	
	std::cout << "stringPTR            : "<< *stringPTR << std::endl;
	std::cout << "stringREF            : "<< stringREF << std::endl;
	return (0);
}

