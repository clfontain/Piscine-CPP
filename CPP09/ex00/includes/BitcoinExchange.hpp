#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <regex.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <ctype.h>
#include <algorithm>

#define DATE "^[0-9]{4}-(((0[13578]|(10|12))-(0[1-9]|[1-2][0-9]|3[0-1]))|(02-(0[1-9]|[1-2][0-9]))|((0[469]|11)-(0[1-9]|[1-2][0-9]|30)))$"

class BitcoinExchange {

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cpy);
		BitcoinExchange& operator=(const BitcoinExchange &cpy);
		int open_file(const char *path_file, char sep);
		int process_input_file(const char *path_file, char sep);
		void print_data( void );
		int parse_date(std::string str);
		int parse_double(std::string str);
		int parse_range(double nbr);
		float calcul_price(std::string date, float res);
		std::map<std::string, float>::iterator find_closed(std::string date);
	private:
		std::map<std::string, float, std::greater<std::string> > data;
		regex_t regex_date;
};

#endif
