#include "BitcoinExchange.hpp"



BitcoinExchange::BitcoinExchange()
{
	if (regcomp(&this->regex, DATE, REG_EXTENDED))
	{
		std::cerr << "REGCOMP FAILED\n";
		exit (1);
	}	
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
   (void)cpy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
	if (this != &cpy)
	{
	  
	}
	return (*this);
}

int BitcoinExchange::parse_date(std::string str)
{
	if (regexec(&this->regex, str.c_str(), 0, NULL, 0) != 0)
	{
		std::cerr << "INVALID DATE FORMAT\n";
		return (1);
	}	
	else
		return (0);
}

int BitcoinExchange::process_input_file(const char *path_file, char sep)
{
	std::ifstream file(path_file);
	std::string line, price, date;

	size_t found;
	float res = 0;
	if (file.is_open())
	{
		while (getline(file, line))
		{
			found = line.find(sep, 0);
			if (found != std::string::npos)
			{
				date = line.substr(0, found);
				price = line.substr(found + 1, strlen(line.c_str()) - found + 1);
				std::istringstream price2(price);
				price2 >> res;
				data.insert(std::pair<std::string, float>(date, res));
			}	
			//std::cout << line << std::endl;
		}	
	}
	return (0);
}


int BitcoinExchange::open_file(const char *path_file, char sep)
{
	std::ifstream file(path_file);
	std::string line, price, date;
	size_t found;
	float res = 0;
	(void)res;
	(void)sep;
	(void)price;
	(void)date;
	if (file.is_open())
	{
		getline(file, line);
		if (line != "date,exchange_rate")
			std::cerr << "INVALID FIRST LINE\n";
		while (getline(file, line))
		{
			found = line.find(sep, 0);
			if (found != std::string::npos)
			{
				date = line.substr(0, found);
				if (parse_date(date) == 1)
					return (1);
				price = line.substr(found + 1, strlen(line.c_str()) - found + 1);
				std::istringstream price2(price);
				price2 >> res;
				data.insert(std::pair<std::string, float>(date, res));	
			}
		}	
	}
	else   
		return (1);
	print_data();
	return (0);
}

void BitcoinExchange::print_data( void )
{
	std::map<std::string, float>::iterator it;
	for(it = data.begin(); it != data.end(); it++)
	{
		std::cout <<"[" << it->first <<"]"<< " | " << it->second << std::endl;
	}
}