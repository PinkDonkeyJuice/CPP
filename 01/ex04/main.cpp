/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:13:47 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/17 17:24:03 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string	ft_replace(std::string buffer, const std::string search, const std::string replace)
{
	size_t		pos = 0;
	
	pos = buffer.find(search);
	while (pos != buffer.npos)
	{
		buffer.erase(pos, search.length());
		buffer.insert(pos, replace);
		pos = buffer.find(search, pos + replace.length());
	}
	return (buffer);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		std::cout << "wrong number of arguments" << std::endl << "Need file_name and two strings";
	else
	{
		const std::string	file_name = argv[1];
		const std::string	search = argv[2];
		const std::string	replace = argv[3];
		std::string			buffer;
		std::ofstream		output;
		std::ifstream		input;

		input.open(file_name);
		if (input.is_open() == true)
		{
			output.open(file_name + ".replace");
			if (output.is_open() == true)
			{
				while (std::getline(input, buffer))
				{
					buffer = ft_replace(buffer, search, replace);
					output << buffer;
					if (input.peek() != EOF)
						output << std::endl;
				}
			}
			else
			{
				std::perror("Can't open output file");
				input.close();
				return (EXIT_FAILURE);
			}
			input.close();
		}
		else
		{
			std::perror("Can't open input file");
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}