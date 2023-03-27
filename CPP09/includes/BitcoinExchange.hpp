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

	private:
		std::map<std::string, float> data;
		regex_t regex;
};

#endif