/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:42:19 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/21 10:57:46 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include <fstream>
#include <istream>

int cut_and_replace(std::string s1, std::string s2, char *argv)
{
	std::size_t pos;
	std::string buff;
	std::ifstream infile(argv);
	std::string outfile_name = argv;
	
	outfile_name.append(".replace");
	if (infile.is_open() == false)
	{
		std::cerr << "Error infile is missing" << std::endl;
		return (1);
	}
	std::ofstream outfile(outfile_name.data());
	if (outfile.is_open() == false)
	{
		std::cerr << "Error outfile" << std::endl;
		return (infile.close(), 1);
	}
	while (infile.good() && outfile.good())
	{
		std::getline(infile, buff);
		pos = buff.find(s1, 0);
		while (pos != std::string::npos)
		{
			buff.erase(pos, s1.length());
			buff.insert(pos, s2);
			pos = buff.find(s1, pos);
		}
		outfile << buff;
		outfile << std::endl;
		if (infile.eof() == true)
			break;
	}
	infile.close();
	outfile.close();
	return (0);
}


int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "ERROR, Sed take 3 arguments : <filename> ; <string_to_find> ; <string_to_replace>" << std::endl;
		return (1);
	}
	if (strlen(argv[2]))
	{
		if (cut_and_replace(argv[2], argv[3], argv[1]) == 1)
			return (1);
	}		
	return (0);
}

