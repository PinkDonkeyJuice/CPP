#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    //std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
    //std::cout << "BitcoinExchange destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref)
{
	*this = ref;
	//std::cout << "BitcoinExchange Copy Constructor called";
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref)
{
	std::map<std::string, double>::const_iterator it = (ref.mp).begin();

	while (it != ref.mp.end())
	{
		this->mp[it->first] = it->second;
		it++;
	}
	return *this;
}

bool	BitcoinExchange::loadCSV(std::string db_name)
{
	double value;
	std::string line, date;
	std::ifstream db_file(db_name.c_str());

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

void	BitcoinExchange::check_date(const std::string date, int i)
{
	int day, month, year;

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		if (i == 1)
			return ;
		throw(InvalidDateException(date));
	}
		std::istringstream daystream(date.substr(8,2));
	std::istringstream monthstream(date.substr(5,2));
	std::istringstream yearstream(date.substr(0,4));

	daystream >> day;
	monthstream >> month;
	yearstream >> year;
	if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2024)
		throw(InvalidDateException(date));
}

double	BitcoinExchange::find_closest_value(const std::string date)
{
	std::map<std::string, double>::iterator it;

	if (this->mp.empty())
	{
		throw(InvalidDateException(date));
	}
	it = this->mp.lower_bound(date);
	if (it == this->mp.begin() || it->first == date)
		return it->second;
	--it;
	return it->second;
}

double	BitcoinExchange::convert_amount(const std::string str_amount, int i)
{
	std::istringstream intstream(str_amount);
	int int_amount;
	std::istringstream floatstream(str_amount);
	double float_amount;

	if (intstream >> int_amount && intstream.eof() && int_amount >= 0 && int_amount <= 1000)
		return (static_cast<double>(int_amount));
	else if (floatstream >> float_amount && floatstream.eof() && float_amount >= 0 && float_amount <= 1000)
		return (float_amount);
	else if (i == 1)
		return -1;
	throw(InvalidNumberException());
}

void	BitcoinExchange::calc_values(const std::string infile_name)
{
	size_t i = 0;
	std::string line, date, seperator, str_amount;
	double amount, value;

	std::ifstream infile(infile_name.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error opening input file" << std::endl;
		return ;
	}
	while (std::getline(infile, line))
	{
		i++;
		try
		{
			std::istringstream ss(line);
			if (!std::getline(ss, date, ' ') || date.empty())
				throw(InvalidFormatException());
			check_date(date, i);
			if (!std::getline(ss, seperator, ' ') || seperator != "|")
				throw(InvalidFormatException());
			if (!(ss >> str_amount) || !ss.eof())
				throw(InvalidFormatException());
			amount = convert_amount(str_amount, i);
			if (amount != -1)
			{
				value = this->find_closest_value(date);
				std::cout << date << ": " << amount << " => " << amount * value << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
