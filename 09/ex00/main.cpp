#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	BitcoinExchange btc;

	if (argc != 1)
	{
		std::cout << "Need one argument: the input file" << std::endl;
	}
	else
	{
		btc.loadCSV("data.csv");
		btc.calc_values(argv[1]);
		return 0;
	}
	return 1;
}