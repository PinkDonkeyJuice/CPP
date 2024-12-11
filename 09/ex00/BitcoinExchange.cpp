#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "BitcoinExchange destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref)
{
     std::cout << "BitcoinExchange Copy Constructor called";
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref)
{

}

bool	BitcoinExchange::loadCSV(const std::string db_name)
{
	std::ifstream db_file(db_name);
	if (!db_file.is_open())
	{
		std::cerr << "File couldn't be open" << std::endl;
		return false;
	}
	std::string line, date;
	std::getline(db_file, line);
	while(std::getline(db_file, line))
}
