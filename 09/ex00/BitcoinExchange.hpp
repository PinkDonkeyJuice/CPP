#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iterator>

class BitcoinExchange
{
private:
	std::map<std::string, double> mp;
public:
    BitcoinExchange();
    BitcoinExchange(const  BitcoinExchange &copy);
    ~BitcoinExchange();

	bool	loadCSV(std::string db_name);
	void	calc_values(const std::string infile_name);
	double find_closest_value(const std::string date);
	void check_date(const std::string date);
	double	convert_amount(const std::string str_amount);


	class InvalidTypeException: public std::exception
	{
		public:
			const char *what() const throw()
			{
				return("Amount type is invalid: Need float or positive int between 1 and 100");
			}
	};
	class InvalidDateException: public std::exception
	{
		public:
			const char *what() const throw()
			{
				return("Date is invalid: Need valid YYYY-MM-DD format");
			}
	};

    BitcoinExchange &operator=(const  BitcoinExchange &src);
};
