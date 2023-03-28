#include "BitcoinExchange.hpp"



BitcoinExchange::BitcoinExchange()
{
	if (regcomp(&this->regex_date, DATE, REG_EXTENDED))
	{
		std::cerr << "REGCOMP FAILED\n";
		exit (1);
	}
}

BitcoinExchange::~BitcoinExchange()
{
	regfree(&this->regex_date);
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

int BitcoinExchange::parse_range(double nbr)
{
	if (nbr < 0)
	{
		std::cout << "Error: not a positive number.\n";
		return (1);
	}
	if (nbr > 1000)
	{
		std::cout << "Error: too large a number.\n";
		return (1);
	}
	return (0);
}

int BitcoinExchange::parse_double(std::string str)
{
	//std::cout << str << std::endl;
	for(size_t i = 0; i < strlen(str.c_str()); i++)
	{
		if (str[0] == '.'|| str[strlen(str.c_str()) - 1] == '.')
		{
			std::cout << "Error: bad input\n";
			return (1);
		}
		if (i != 0 && isdigit(str[i]) == 0 && str[i] != '.')
		{
			std::cout << "Error: bad input\n";
			return (1);
		}	
	}
	
	return (0);	
}

int BitcoinExchange::parse_date(std::string str)
{
	if (regexec(&this->regex_date, str.c_str(), 0, NULL, 0) != 0)
	{
		std::cout << "Error: bad input => " << str <<std::endl;
		return (1);
	}	
	else
		return (0);
}

std::map<std::string, float>::iterator BitcoinExchange::find_closed(std::string date)
{
	if (this->data.lower_bound(date) == this->data.end())
		return (--this->data.end());
	return (data.lower_bound(date));
}
int BitcoinExchange::calcul_price(std::string date, float res)
{
	std::map<std::string, float>::iterator it;
	//it = data.find(date);
	//std::cout << it->first << std::endl;
	std::cout << find_closed(date)->first << std::endl;
	//std::cout << it->first << std::endl;
	(void)res;
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
		getline(file, line);
		if (line != "date | value")
		{
			std::cerr << "INVALID FIRST LINE\n";
			return (1);
		}	
		while (getline(file, line))
		{
			found = line.find(sep, 0);
			if (found != std::string::npos)
			{
				if (line[found - 1] != ' ' || line[found + 1] != ' ')
				{
					std::cout << "INVALID LINE FORMAT\n";
					continue;
				}	
				line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
				date = line.substr(0, found - 1);
				//std::cout << date << std::endl;
				price = line.substr(found, strlen(line.c_str()) - found);
				std::istringstream price2(price);
				price2 >> res;
				if (parse_date(date) == 0 && parse_double(price) == 0 && parse_range(res) == 0)
					calcul_price(date, res);
			}
			else
			{
				std::cout << "Error: bad input => " << line <<std::endl;
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
				//data.insert(std::pair<std::string, float>(date, res));	
				data[date] = res;
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