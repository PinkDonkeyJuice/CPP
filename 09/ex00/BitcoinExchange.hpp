#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
private:
	std::map<std::string, double> mp;
public:
    BitcoinExchange();
    BitcoinExchange(const  BitcoinExchange &copy);
    ~BitcoinExchange();

	bool	loadCSV(const std::string db_name);
	void	calc_value(const std::string infile_name);
    BitcoinExchange &operator=(const  BitcoinExchange &src);
};