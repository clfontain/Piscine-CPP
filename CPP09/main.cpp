#include "BitcoinExchange.hpp"


/*void result(std::map<std::string, float> data, std::map<std::string, float> data2)
{
	std::map<std::string, float> data3;
	std::map<std::string, float>::iterator it;
	std::map<std::string, float>::iterator it2;
	for(it = data2.begin(); it != data2.end(); it++)
	{
		it2 = data.find(data2->first);
		data3.insert(std::pair<std::string, float>(it->first, it2->second * it->second));
	}
}*/





int main(int argc, char **argv)
{
	BitcoinExchange btc;
	if (argc != 2)
		return(1);
	(void)argv;
	btc.open_file("./data.csv", ',');
	btc.process_input_file(argv[1], '|');

	return (0);
}