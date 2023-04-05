#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange btc;
	if (argc != 2)
	{
		std::cerr << "Error\nNeed an input file\n";
		return(1);
	}	
	if (btc.open_file("./data.csv", ',') == 1)
		return (1);
	if (btc.process_input_file(argv[1], '|') == 1)
		return (1);

	return (0);
}
