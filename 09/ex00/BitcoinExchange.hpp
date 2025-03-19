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
	void check_date(const std::string date, int i);
	double	convert_amount(const std::string str_amount, int i);


	class InvalidNumberException: public std::exception
	{
		public:
			const char *what() const throw()
			{
				return("Error: bad input => Need int or float between 0 and 1000");
			}
	};
	class InvalidFormatException: public std::exception
	{
		public:
			const char *what() const throw()
			{
				return("Error: bad input => Need date | value");
			}
	};
	
	class InvalidDateException: public std::exception
	{
		private:
			std::string _message;

		public:
			InvalidDateException(std::string date)
			{
				_message = "Error date is invalid: " + date  + " => Need valid YYYY-MM-DD format";
			}
			virtual ~InvalidDateException() throw()
			{
			}
			const char *what() const throw()
			{
				return(_message.c_str());
			}
	};

    BitcoinExchange &operator=(const  BitcoinExchange &src);
};
