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
	double value;
	std::string line, date;

	std::ifstream db_file(db_name);
	if (!db_file.is_open())
	{
		std::cerr << "Error opening data_base file" << std::endl;
		return false;
	}
	std::getline(db_file, line);
	while(std::getline(db_file, line))
	{
		std::istringstream ss(line);
		std::getline(ss, date, ',');
		ss >> value;
		this->mp[date] = value;
	}
	db_file.close();
	return true;
}

bool	BitcoinExchange::check_date(const std::string date, size_t i)
{
	int day, month, year;

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		throw(InvalidDateException());
	std::istringstream daystream(date.substr(8,2));
	std::istringstream monthstream(date.substr(5,2));
	std::istringstream yearstream(date.substr(0,4));

	daystream >> day;
	monthstream >> month;
	yearstream >> year;
	if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2024)
		throw(InvalidDateException());
}

double	BitcoinExchange::find_closest_value(const std::string date)
{
	if (this->mp.empty())
	{
		throw(InvalidDateException());
	}
	auto it = this->mp.lower_bound(date);
	if (it == this->mp.begin() && date <= it->first)
		throw(InvalidDateException());
	else if (it == this->mp.begin())
		return it->second;
	if (it == this->mp.end() && date > it->first)
		return it->second;
	--it;
	return it->second;
}

double	BitcoinExchange::convert_amount(const std::string str_amount)
{
	std::istringstream intstream(str_amount);
	int int_amount;
	std::istringstream floatstream(str_amount);
	double float_amount;

	if (intstream >> int_amount && intstream.eof() && int_amount >= 0 && int_amount <= 1000)
		return (static_cast<double>(int_amount));
	if (floatstream >> float_amount && floatstream.eof() && float_amount >= 0 && float_amount <= 1000)
		return (float_amount);
	throw(InvalidTypeException());
}

void	BitcoinExchange::calc_values(const std::string infile_name)
{
	size_t i = 0;
	std::string line, date, seperator, str_amount;
	double amount, value;

	std::ifstream infile(infile_name);
	if (!infile.is_open())
	{
		std::cerr << "Error opening input file" << std::endl;
		return ;
	}
	while (std::getline(infile, line))
	{
		i++;
		std::istringstream ss(line);
		std::getline(ss, date, ' ');
		check_date(date, i);
		std::getline(ss, seperator, ' ');
		if (seperator != "|")
		{
			std::cerr << "Invalid input\nLine " << i << " : need 'date | value' format" << std::endl;
			return ;
		}
		ss >> str_amount;
		try
		{
			amount = convert_amount(str_amount);
			if (this->mp.count(date) <= 0)
			{
				value = this->find_closest_value(date);
			}
			std::cout << amount * value << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
